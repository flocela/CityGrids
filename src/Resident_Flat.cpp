#include "Resident_Flat.h"

Resident_Flat::Resident_Flat (int id,
                              Resident::Color color, 
                              Resident::ResidentType residentType,
                              double allowedMovementDistance,
                              double happinessGoal,
                              double happinessValue):
    Resident(id, color, residentType, allowedMovementDistance, happinessGoal),
    _happiness_func{happinessValue}
{
    
}

double Resident_Flat::getHappiness(std::vector<Resident::Color> neighbors) const
{
    int total = neighbors.size();
    int like  = 0;
    int diff  = 0;

    return _happiness_func.getHappiness(total, like, diff);
}