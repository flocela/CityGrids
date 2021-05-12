#ifndef CITYFACTORY_GRID_H
#define CITYFACTORY_GRID_H

#include "CityFactory.h"
#include "City_Grid.h"
#include <string>
#include "Question.h"

class CityFactory_Grid: public CityFactory
{
    public:
        CityFactory_Grid ();
        CityFactory_Grid (const CityFactory_Grid& obj) = default;
        CityFactory_Grid (CityFactory_Grid&& obj) noexcept = default;
        CityFactory_Grid& operator=(const CityFactory_Grid& obj) = default;
        CityFactory_Grid& operator=(CityFactory_Grid&& obj) noexcept = default;

        std::unique_ptr<City>  createCity (UI& ui) override;
        std::string toString () override;
    private:
        std::unique_ptr<Question> _question;
};

#endif