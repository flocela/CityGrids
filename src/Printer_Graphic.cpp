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
{/*
    SDL_RenderClear(sdl_renderer);
    SDL_Surface* image = SDL_LoadBMP("test.bmp");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(sdl_renderer, image);
    SDL_RenderCopy(sdl_renderer, texture, NULL, NULL);
    SDL_RenderPresent(sdl_renderer);*/
    //_renderer.Render();
    //std::thread t1(&Renderer::poll, _renderer);
    _renderer.Render();
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
        if (!mapContains(residentsPerAddress, address))
        {   
            // No resident has this address. So this house is empty.
            colorKey = Color::absent;
        }
        else
        {   
            Resident* res = residentsPerAddress[address];
            colorKey = res->getColor();
        }

        if (!mapContains(coordinatesPerColor, colorKey))
        {
            std::vector<Coordinate> newCoordinateVector = {};
            coordinatesPerColor[colorKey] = newCoordinateVector;
        }
        coordinatesPerColor[colorKey].push_back(coord);
        count ++;
    }
    
    _renderer.RenderCity(coordinatesPerColor, Coordinate{50, 50});
} 

void Printer_Graphic::keepScreen()
{
    SDL_Event event;
    bool running = true;
    int counter = 0;

    while (running)
    {   
        counter++;
        if (SDL_WaitEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    std::cout << " SDL_QUIT" << std::endl;
                    running = false;
            }
        }
    }
    std::cout << "End of keepScreen()" <<std::endl;
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
