#include "Printer_Graphic.h"

#include <vector>
#include <map>
#include <utility>

void Printer_Graphic::print(std::map<int, Resident*> residentPerHouse, 
                            std::map<Coordinate, int> housePerCoordinate,
                            int run,
                            int totRuns,
                           	std::string title)
{   
    std::vector<std::array<int, 3>> colors = { {255, 0, 0},
                                               {0, 255, 0},
                                               {0, 0, 255},
                                               {0, 0, 0,} };

    

    std::map<Coordinate, int> colorPerResidentColor;

    for (auto const& x : housePerCoordinate)
    {
        Coordinate coord = x.first;
        int        house = x.second;
        if (residentPerHouse.count(house) == 0)
        {
            colorPerResidentColor[coord] = 3;
            continue;
        }
        Resident* res = residentPerHouse[house];
        if (res->getColor() == Resident::Color::red)
        {
            colorPerResidentColor[coord] = 0;
        }
        else if (res->getColor() == Resident::Color::green)
        {
            colorPerResidentColor[coord] = 1;
        }
        else if (res->getColor() == Resident::Color::blue)
        {
            colorPerResidentColor[coord] = 2;
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
