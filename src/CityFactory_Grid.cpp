#include "CityFactory_Grid.h"
#include "Question_Int.h"

CityFactory_Grid::CityFactory_Grid ()
{
    _question = std::make_unique<Question_Int>(0,
                                         1,
                                         100,
                                         "Enter the width of the grid. How many"
                                         " houses wide each side is. The minimum"
                                         " width is 1 house. The maximum width is"
                                         " 100 houses.",
                                         "Nope, that's not a whole number. Should"
                                         " be a number without any decimals.",
                                         "That number is either too small or too"
                                         " large. Minimum allowed width is 1,"
                                         " maximum allowed width is 100."); 
}


std::unique_ptr<City> CityFactory_Grid::createCity (UI& ui)
{
    ui.getAnswer(*(_question.get()));
    if (_question->hasValidAnswer())
    {
        return std::make_unique<City_Grid>(std::stoi(_question->getAnswer()));
    }
    else
    {
        throw "Can not get information needed to make a city"
        " from the user.";
    }
}

std::string CityFactory_Grid::toString ()
{
    return "CityFactory_Grid";
}