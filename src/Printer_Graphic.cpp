#include "Printer_Graphic.h"

#include <vector>
#include <map>
#include <utility>
#include <thread>
#include <chrono>
#include <iostream>

bool mapContains (std::map<Color, std::vector<Coordinate>> aMap, Color aKey);
bool mapContains (std::map<int, Resident*> aMap, int aKey);

Printer_Graphic::Printer_Graphic (
    const std::size_t screen_width,
    const std::size_t screen_height,
    const std::size_t grid_width, 
    const std::size_t grid_height
): _renderer{screen_width, screen_height, grid_width, grid_height},
   _keep_polling{true}
{
    for (ColorInfo colorInfo : _the_colors)
    {

        _rgba_per_color[colorInfo._my_color];
    }

}

void Printer_Graphic::printScreen ()
{
    _renderer.Render();
    //std::thread t1(&Renderer::poll, _renderer);
    _keep_polling = true;
}

void Printer_Graphic::print (
    std::map<int, Resident*> residentsPerAddress, 
    std::map<Coordinate, int> addressPerCoordinate,
    int run,
    int totalRuns,
    std::string title
)
{  
    std::map<Color, std::vector<Coordinate>> coordinatesPerColor = {};
    int count = 0;
    for (auto const& x : addressPerCoordinate)
    {
        Coordinate coord = x.first;
        int address = x.second;
        Color colorKey;
        std::cout << "count: " << count << std::endl;
        std::cout << "address" << address << std::endl;
        if (!mapContains(residentsPerAddress, address))
        {   std::cout << "Printer_Graphic line 53 " << std::endl;
            // No resident has this address. So this house is empty.
            colorKey = Color::absent;
        }
        else
        {   std::cout << "Printer_Graphic line 58 address: " << address << std::endl;
            Resident* res = residentsPerAddress[address];
            std::cout<< res->getID() << std::endl;
            std::cout << "Printer_Graphic line 61" << std::endl;
            colorKey = res->getColor();
            std::cout << "Printer_Graphic line 63 " << std::endl;
        }

        if (!mapContains(coordinatesPerColor, colorKey))
        {
            std::cout << "Printer_Graphic line 68 " << std::endl;
            std::vector<Coordinate> newCoordinateVector = {};
            coordinatesPerColor[colorKey] = newCoordinateVector;
        }
        coordinatesPerColor[colorKey].push_back(coord);
        count ++;
    }
    
    _renderer.RenderCity(coordinatesPerColor);
} 

void Printer_Graphic::keepScreen()
{
    std::cout << "Printer_Graphic line 72" << std::endl;
    SDL_Event e;
    int counter = 0;
    while (SDL_WaitEvent(&e) != 0)
    {   
        std::cout << "in SDL_WaitEvent while loop" << counter << std::endl;
        counter ++;
        if (e.type == SDL_QUIT)
        {
            //_keep_polling = false;
            break;
        }
    }
}
void Printer_Graphic::printResidents(std::map<int, Resident*> addressPerResident,
                                     std::map<int, Coordinate> coordinatePerAddress,
                                     int run,
                                     int totRuns,
                           			 std::string title)
{
}

bool mapContains (std::map<Color, std::vector<Coordinate>> aMap, Color aKey)
{
    return aMap.count(aKey);
}

bool mapContains (std::map<int, Resident*> aMap, int aKey)
{
    return aMap.count(aKey);
}
