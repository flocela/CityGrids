#ifndef RESIDENT_H
#define RESIDENT_H

#include <vector>

class Resident{
    public:
        enum Color { red, blue, green, absent };
        enum ResidentType { flat, rising, falling, stepup, stepdown };
        Resident (int id,
                  Color color, 
                  ResidentType residentType,
                  double allowedMovementDistance,
                  double happinessGoal);
        Resident (const Resident& obj) = default;
        Resident (Resident&& obj) noexcept = default;
        Resident& operator= (const Resident& obj) = default;
        Resident& operator= (Resident&& obj) noexcept = default;
        virtual ~Resident () = default;

        int getID() { return _ID; }
        virtual Color getColor () const { return _color; };
        virtual ResidentType getResidentType () const { return _resident_type; };
        virtual double getAllowedMovementDistance () const { return _allowed_movement_distance; };
        virtual double getHappinessGoal () const { return _happiness_goal; };

        // neighbors vector includes all possible neighbors, so
        // if a neighbors house is empty, Color::absent should
        // be added to neighbors
        virtual double getHappiness (std::vector<Color> neighbors) const = 0;
        
    private:
        Resident::Color _color;
        Resident::ResidentType _resident_type;
        double _allowed_movement_distance;
        double _happiness_goal;
        int _ID;
        static const std::vector<int> residentTypes;
};

#endif