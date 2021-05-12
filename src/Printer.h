#ifndef PRINTER_H
#define PRINTER_H

#include <map>
#include "Resident.h"
#include "Coordinate.h"

class Printer
{   public:
        virtual void print(std::map<int, Resident*> residentPerHouse, 
                           std::map<Coordinate, int> housePerCoordinate) = 0;
        virtual void printResidents(std::map<int, Resident*> housePerResident,
                                    std::map<int, Coordinate> coordinatePerHouse) = 0;
        virtual void printHouses (std::map<int, Coordinate> coordinatePerHouse) = 0;
};

#endif