#include "Converter.h"

std::map<Coordinate, int> Converter::colorPerCoordinate
    (std::map<int, Resident*> residentPerHouse,
     std::map<Coordinate, int> housePerCoordinate,
     std::map<Color, int> intPerColor)
{
    std::map<Coordinate, int> colorPerCoordinate;

    for (auto const& x : housePerCoordinate)
    {
        Coordinate coord = x.first;
        int        house = x.second;
        if (residentPerHouse.count(house) == 0)
        {
            colorPerCoordinate[coord] = intPerColor[Color::absent];
            continue;
        }
        Resident* res = residentPerHouse[house];
        colorPerCoordinate[coord] = intPerColor[res->getColor()];
    }
    return colorPerCoordinate;
}