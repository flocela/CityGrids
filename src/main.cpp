#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <memory>

#include "CityFactory.h"
#include "CityFactory_Grid.h"

/*#include "CityMaker_CMDLine.h"

#include "CityFactory_Grid.h"
#include "ResidentsFactory_Flat.h"
#include "ResidentsFactory.h"
#include "ResidentsMaker_CMDLine.h"*/

class MyClass
{

};

int main() {
  
  	constexpr std::size_t kFramesPerSecond{60};
  	constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  	constexpr std::size_t kScreenWidth{640};
  	constexpr std::size_t kScreenHeight{640};
  	constexpr std::size_t kGridWidth{32};
  	constexpr std::size_t kGridHeight{32};

    CityFactory_Grid cfg = CityFactory_Grid();
  /*
    std::vector<std::unique_ptr<CityFactory>> cityFactories;
    std::vector<std::unique_ptr<MyClass>> myClasses;
    myClasses.emplace_back(std::make_unique<MyClass>());
    

    cityFactories.emplace_back(std::make_unique<CityFactory_Grid>());
    std::vector<CityFactory*> cityFactoryPointers = {};
    for (auto& factory: cityFactories)
    {
        cityFactoryPointers.push_back(factory.get());
    }

    CityMaker_CMDLine cityMaker{};
    std::unique_ptr<City> city = cityMaker.makeCity(cityFactoryPointers);
    std::cout << "main: "<< city->getSize() << std::endl;

    std::vector<std::unique_ptr<ResidentsFactory>> residentFactories;
    residentFactories.emplace_back(std::make_unique<ResidentsFactory_Flat>());
    std::vector<ResidentsFactory*> residentFactoryPointers = {};
    for (auto& factory : residentFactories)
    {
        residentFactoryPointers.push_back(factory.get());
    }
    
    ResidentsMaker_CMDLine residentsMaker{};

    // These residents are not associated with any home at this point. They will be associated
    // via two hashmaps later. A hashmap of resident per home and hashmap of home per resident.
    std::vector<std::unique_ptr<Resident>>residents = 
        residentsMaker.makeResidents(residentFactoryPointers, city->getSize());
    std::cout << "number of residents: " << residents.size();
  */
  

  	Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  	Controller controller;
  	Game game(kGridWidth, kGridHeight);
  	game.Run(controller, renderer, kMsPerFrame);
  	std::cout << "Game has terminated successfully!\n";
  	std::cout << "Score: " << game.GetScore() << "\n";
  	std::cout << "Size: " << game.GetSize() << "\n";
  	return 0;
}