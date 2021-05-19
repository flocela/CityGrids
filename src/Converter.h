#ifndef CONVERTER_H
#define CONVERTER_H

#include "Coordinate.h"
#include <map>
#include "Resident.h"

class Converter
{
    public:
        std::map<Coordinate, int> colorPerCoordinate
            (std::map<int, Resident*> residentsPerHouse,
             std::map<Coordinate, int> housePerCoordinate,
             std::map<Color, int> intPerColor);
                                           

};

#endif