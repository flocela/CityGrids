#include "Printer_Graphic.h"

#include <vector>
#include <map>
#include <utility>
#include "Converter.h"
#include <thread>
#include <chrono>

Printer_Graphic::Printer_Graphic (const std::size_t screen_width,
                                  const std::size_t screen_height,
                                  const std::size_t grid_width, 
                                  const std::size_t grid_height):
_renderer{screen_width, screen_height, grid_width, grid_height}, _keep_polling{true}
{}

void Printer_Graphic::printScreen()
{
    _renderer.Render();
    //std::thread t1(&Renderer::poll, _renderer);
    _keep_polling = true;
}

void Printer_Graphic::print(std::map<int, Resident*> residentPerHouse, 
                            std::map<Coordinate, int> housePerCoordinate,
                            int run,
                            int totRuns,
                           	std::string title)
{   
    Converter converter{};
    std::map<Color, int> intPerColor = {};
    intPerColor[Color::absent] = 0;
    intPerColor[Color::red]    = 1;
    intPerColor[Color::blue]   = 2;

    std::map<Coordinate, int> colorPerResidentColor =
        converter.colorPerCoordinate(residentPerHouse,
                                     housePerCoordinate,
                                     intPerColor);
    
    _renderer.RenderCity(colorPerResidentColor);
} 

void Printer_Graphic::keepScreen()
{
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
void Printer_Graphic::printResidents(std::map<int, Resident*> housePerResident,
                                     std::map<int, Coordinate> coordinatePerHouse,
                                     int run,
                                     int totRuns,
                           			 std::string title)
{
}
void Printer_Graphic::printHouses (std::map<int, Coordinate> coordinatePerHouse,
                                   int run,
                                   int totRuns,
                           		   std::string title)
{

}
