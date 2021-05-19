#include "catch.hpp"
#include "../src/Converter.h"
#include "../src/Resident_Flat.h"

TEST_CASE("converts an empty city to a Coordinate map")
{
    std::map<int, Resident*> residentPerHouse = {};
    std::map<Coordinate, int> housePerCoordinate = {};
    std::map<Color, int> intPerColor = {};

    // Make coordinates in a simple grid pattern
    int counter = 0;
    for (int x=0; x< 4; ++x)
    {
        for (int y=0; y<6; ++y)
        {
            Coordinate coord{x, y};
            housePerCoordinate[coord] = counter;
            counter++;
        }
    }

    // Every coordinate maps to an empty house i.e.. Color::absent
    std::map<Coordinate, int> colorPerCoordinateAnswer = {};
    for (int x=0; x< 4; ++x)
    {
        for (int y=0; y<6; ++y)
        {
            Coordinate coord{x, y};
            colorPerCoordinateAnswer[coord] = 0;
        }
    }

    // Converter creates a map of coordinates that map to zero.
    // Zero is linked to Color::absent
    Converter converter{};
    intPerColor[Color::absent] = 0;
    std::map<Coordinate, int> city = 
        converter.colorPerCoordinate(residentPerHouse, 
                                     housePerCoordinate, 
                                     intPerColor);

    // map from converter should equal the map colorPerCoordinateAnswer
    REQUIRE(colorPerCoordinateAnswer.size() == city.size());
    for (auto const& x : colorPerCoordinateAnswer)
    {
        REQUIRE(city.count(x.first) == 1);
        REQUIRE(city[x.first] == colorPerCoordinateAnswer[x.first]);
    }
}

TEST_CASE("converts a complicated city to a Coordinate map")
{
    // I'm defining a complicated city as the following:
    // city perimeter has all empty houses.
    // odd house numbers have Color::blue
    // even house numbers have Color::red
    std::map<int, Resident*> residentPerHouse = {};
    std::map<Coordinate, int> housePerCoordinate = {};
    std::map<Color, int> intPerColor = {};

    // Make coordinates in a simple grid pattern
    int counter = 0;
    for (int x=0; x< 4; ++x)
    {
        for (int y=0; y<6; ++y)
        {
            Coordinate coord{x, y};
            housePerCoordinate[coord] = counter;
            counter++;
        }
    }

    intPerColor[Color::absent] = 0;
    intPerColor[Color::red]    = 1;
    intPerColor[Color::blue]   = 2;

    // Residents assigned to house id.
    for (int x=0; x< 4; ++x)
    {
        for (int y=0; y<6; ++y)
        {
            Coordinate coord{x, y};
            int id = (x * 6) + y;

             if (x==0 || y==0 || x==3 || y==5)
             {
               // Don't add it
             }
            else if (id % 2 == 0)
            {
                auto res = new Resident_Flat{id,
                                             Color::red,
                                             0,
                                             0,
                                             0};
                residentPerHouse[id] = res;
            }
                
            else
            {
                auto res = new Resident_Flat{id,
                                             Color::blue,
                                             0,
                                             0,
                                             0};
                residentPerHouse[id] = res;
            }
        }
    }
    
    // The map, mapping every coordinate to the correct integer.
    // The integer represents a Resident::Color.
    std::map<Coordinate, int> colorPerCoordinateAnswer = {};
    for (int x=0; x< 4; ++x)
    {
        for (int y=0; y<6; ++y)
        {
            Coordinate coord{x, y};
            int id = (x * 6) + y;
            if (id % 2 == 0)
                colorPerCoordinateAnswer[coord] = 1;
            else
                colorPerCoordinateAnswer[coord] = 2;
            if (x==0 || y==0 || x==3 || y==5)
                colorPerCoordinateAnswer[coord] = 0;
        }
    }

    Converter converter{};
    std::map<Coordinate, int> city = 
        converter.colorPerCoordinate(residentPerHouse, 
                                     housePerCoordinate, 
                                     intPerColor);

    // map from converter should equal the map colorPerCoordinateAnswer
    REQUIRE(colorPerCoordinateAnswer.size() == city.size());
    for (auto const& x : colorPerCoordinateAnswer)
    {
        REQUIRE(city.count(x.first) == 1);
        REQUIRE(city[x.first] == colorPerCoordinateAnswer[x.first]);
    }

    for (const auto& z : residentPerHouse)
    {
        delete z.second;
    }

}
