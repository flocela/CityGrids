#ifndef COLOR_H
#define COLOR_H

#include <ostream>
#include <vector>


enum class Color { red, blue, green, absent };

struct ColorInfo
{
    Color    _my_color;
    std::string _my_string;
    //std::ostream& toStream (std::ostream& ost) const;
};

/*
std::ostream& operator<< (std::ostream& ost, const ColorInfo& c)
{
    return c.toStream(ost);
}*/


inline std::vector<ColorInfo> _the_colors = {
    {Color::red, "red"},
    {Color::blue, "blue"},
    {Color::green, "green"},
    {Color::absent, "absent"}
};

#endif