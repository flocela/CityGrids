#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <memory>

#include "CityFactory.h"
#include "CityFactory_Grid.h"
#include "CityMaker_CMDLine.h"
#include "CityFactory_Grid.h"
#include "ResidentsFactory_Flat.h"
#include "ResidentsFactory.h"
#include "ResidentsMaker_CMDLine.h"
#include "Converter.h"
#include "Printer_Graphic.h"
#include "Resident_Flat.h"

#include <thread>

std::vector<std::unique_ptr<CityFactory>> initCityFactories ();

std::vector<std::unique_ptr<ResidentsFactory>> initResidentFactories();

std::vector<CityFactory*> getCityFactoryPointers (
    std::vector<std::unique_ptr<CityFactory>>& cityFactories);

std::vector<ResidentsFactory*> getResidentFactoryPointers (
    std::vector<std::unique_ptr<ResidentsFactory>>& residentFactories);

int main() {

    std::vector<std::unique_ptr<CityFactory>> cityFactories;
    std::vector<std::unique_ptr<ResidentsFactory>> residentFactories;
    std::vector<CityFactory*> cityFactoryPointers;
    std::vector<ResidentsFactory*> residentFactoryPointers;

    cityFactories           = initCityFactories();
    residentFactories       = initResidentFactories();
    cityFactoryPointers     = getCityFactoryPointers(cityFactories);
    residentFactoryPointers = getResidentFactoryPointers(residentFactories);    

    CityMaker_CMDLine cityMaker{};
    std::unique_ptr<City> city = cityMaker.makeCity(cityFactoryPointers);

    ResidentsMaker_CMDLine residentsMaker{};

    // These residents are not associated with any home at this point. They will be
    // be associated later via a hashmap of resident per home and hashmap of home 
    // per resident.
    std::vector<std::unique_ptr<Resident>>residents = 
        residentsMaker.makeResidents(residentFactoryPointers, city->getSize());
    std::cout << "number of residents: " << residents.size();
    /*

    std::vector<std::array<int, 3>> colors = { {255, 0, 0},
                                               {0, 255, 0},
                                               {0, 0, 255},
                                               {0, 0, 0,} };

    std::map<Coordinate, int> colorPerCoordinateAnswer = {};
    for (int x=0; x< 4; ++x)
    {
        for (int y=0; y<6; ++y)
        {
            Coordinate coord{x, y};
            int id = (x * 6) + y;
            if (id % 2 == 0)
                colorPerCoordinateAnswer[coord] = 1;
            else
                colorPerCoordinateAnswer[coord] = 2;
            if (x==0 || y==0 || x==3 || y==5)
                colorPerCoordinateAnswer[coord] = 0;
        }
    }

    for (const auto& z: colorPerCoordinateAnswer)
    {
      if (z.second == 0)
        std::cout << "main: (" << z.first.getX() << ", " << z.first.getY() << ") is zero" << std::endl;
      if (z.second == 1)
        std::cout << "main: (" << z.first.getX() << ", " << z.first.getY() << ") is one" << std::endl;
      if (z.second == 2)
        std::cout << "main: (" << z.first.getX() << ", " << z.first.getY() << ") is two" << std::endl;
      if (z.second == 3)
        std::cout << "main: (" << z.first.getX() << ", " << z.first.getY() << ") is three" << std::endl;
    }*/

    Printer_Graphic printer{640, 960, 20, 20};
    // I'm defining a complicated city as the following:
    // city perimeter has all empty houses.
    // odd house numbers have Color::blue
    // even house numbers have Color::red
    std::map<Coordinate, int> housePerCoordinate = {};
    std::map<Color, int> intPerColor = {};
    std::map<int, Resident*> residentPerHouse = {};
    
    // Make coordinates in a simple grid pattern
    int counter = 0;
    for (int x=0; x< 4; ++x)
    {
        for (int y=0; y<6; ++y)
        {
            Coordinate coord{x, y};
            housePerCoordinate[coord] = counter;
            counter++;
        }
    }

    intPerColor[Color::absent] = 0;
    intPerColor[Color::red]    = 1;
    intPerColor[Color::blue]   = 2;

    // Residents assigned to house id.
    for (int x=0; x< 4; ++x)
    {
        for (int y=0; y<6; ++y)
        {
            Coordinate coord{x, y};
            int id = (x * 6) + y;

             if (x==0 || y==0 || x==3 || y==5)
             {
               // Don't add it
             }
            else if (id % 2 == 0)
            {
                auto res = new Resident_Flat{id,
                                             Color::red,
                                             0,
                                             0,
                                             0};
                residentPerHouse[id] = res;
            }
                
            else
            {
                auto res = new Resident_Flat{id,
                                             Color::blue,
                                             0,
                                             0,
                                             0};
                residentPerHouse[id] = res;
            }
        }
    }
    printer.printScreen();

    printer.print(residentPerHouse, housePerCoordinate, 1, 1, "Title");
    printer.keepScreen();

    for (const auto& z : residentPerHouse)
    {
        delete z.second;
    }

    //Renderer renderer{640, 960, 20, 20};
    //renderer.RenderCity(colorPerCoordinateAnswer, colors);
    //SDL_Delay(5000);

  /*

  	Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  	Controller controller;
  	Game game(kGridWidth, kGridHeight);
  	game.Run(controller, renderer, kMsPerFrame);
  	std::cout << "Game has terminated successfully!\n";
  	std::cout << "Score: " << game.GetScore() << "\n";
  	std::cout << "Size: " << game.GetSize() << "\n";*/
  	return 0;
}

/*
constexpr std::size_t kFramesPerSecond{60};
  	constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  	constexpr std::size_t kScreenWidth{640};
  	constexpr std::size_t kScreenHeight{640};
  	constexpr std::size_t kGridWidth{32};
  	constexpr std::size_t kGridHeight{32};*/

std::vector<std::unique_ptr<CityFactory>> initCityFactories ()
{
    std::vector<std::unique_ptr<CityFactory>> cityFactories = {};
    cityFactories.emplace_back(std::make_unique<CityFactory_Grid>());
    return cityFactories;
}

std::vector<std::unique_ptr<ResidentsFactory>> initResidentFactories()
{
    std::vector<std::unique_ptr<ResidentsFactory>> residentFactories = {};
    residentFactories.emplace_back(std::make_unique<ResidentsFactory_Flat>());
    return residentFactories;
}

std::vector<CityFactory*> getCityFactoryPointers (
    std::vector<std::unique_ptr<CityFactory>>& cityFactories)
{
    std::vector<CityFactory*> cityFactoryPointers = {};
    for (auto& factory: cityFactories)
    {
        cityFactoryPointers.push_back(factory.get());
    }
     std::cout << "line 206 " << cityFactoryPointers[0]->toString() << std::endl;
    return cityFactoryPointers;
}

std::vector<ResidentsFactory*> getResidentFactoryPointers (
    std::vector<std::unique_ptr<ResidentsFactory>>& residentFactories)
{
    std::vector<ResidentsFactory*> residentFactoryPointers = {};
    for (auto& factory : residentFactories)
    {
        residentFactoryPointers.push_back(factory.get());
    }
    return residentFactoryPointers;
}