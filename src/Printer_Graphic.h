#ifndef PRINTER_Graphic_H
#define PRINTER_Graphic_H

#include "Printer.h"

class Printer_Graphic : public Printer
{   
    public:
        void print(std::map<int, Resident*> residentPerHouse, 
                   std::map<Coordinate, int> housePerCoordinate,
                   int run,
                   int totRuns,
                   std::string title) override;
        void printResidents(std::map<int, Resident*> housePerResident,
                            std::map<int, Coordinate> coordinatePerHouse,
                            int run,
                            int totRuns,
                            std::string title) override;
        void printHouses (std::map<int, Coordinate> coordinatePerHouse,
         				  int run,
                          int totRuns,
                          std::string title) override;
        
};

#endif