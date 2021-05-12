#ifndef CITYFACTORY_H
#define CITYFACTORY_H

#include "City.h"
#include "UI.h"
#include <map>
#include <string>
#include <memory>

class CityFactory
{
    public:
        virtual std::unique_ptr<City> createCity (UI& ui) = 0;
        virtual std::string toString () = 0;
};

#endif