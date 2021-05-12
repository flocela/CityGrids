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
        virtual ~CityFactory() = default;
        virtual std::string toString () = 0;
};

#endif