#include "CityMaker_CMDLine.h"
#include "UI_CMDLine.h"
#include <iostream>

std::unique_ptr<City> CityMaker_CMDLine::makeCity (std::vector<CityFactory*> cityFactories) const
{
    UI_CMDLine ui{};
    std::vector<std::string> namesOfCityFactories = {};
    for (auto& factory : cityFactories)
    {
        namesOfCityFactories.push_back(factory->toString());
    }

    int cityChoice = ui.menu("Choose a city type by typing the"
                            " corresponding number.",
                            namesOfCityFactories);
    return cityFactories[cityChoice]->createCity(ui);
}