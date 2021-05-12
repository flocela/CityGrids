#ifndef PRINTER_CMDLINE_H
#define PRINTER_CMDLINE_H

#include "Printer.h"

class Printer_CMDLine : public Printer
{   
    public:
        void print(std::map<int, Resident*> residentPerHouse, 
                                    std::map<Coordinate, int> housePerCoordinate) override;
        void printResidents(std::map<int, Resident*> housePerResident,
                                             std::map<int, Coordinate> coordinatePerHouse) override;
        void printHouses (std::map<int, Coordinate> coordinatePerHouse) override;
        
};

#endif