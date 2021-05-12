#ifndef RESIDENTFACTORY_FLAT_H
#define RESIDENTFACTORY_FLAT_H

#include "ResidentsFactory.h"
#include "Question_Int.h"
#include "Question_Double.h"

class ResidentsFactory_Flat: public ResidentsFactory
{
    public:
        ResidentsFactory_Flat () = default;
        ResidentsFactory_Flat (const ResidentsFactory_Flat& obj) = default;
        ResidentsFactory_Flat (ResidentsFactory_Flat&& obj) noexcept = default;
        ResidentsFactory_Flat& operator= (const ResidentsFactory_Flat& obj) = default;
        ResidentsFactory_Flat& operator= (ResidentsFactory_Flat&& obj) noexcept = default;
        ~ResidentsFactory_Flat() = default;

        std::vector<std::unique_ptr<Resident>> createResidents (
                                                UI& ui,
                                                int firstID,
                                                int maxCount, 
                                                Resident::Color color) override;
        std::vector<std::unique_ptr<Resident>> createResidents(
                                                UI& ui,
                                                int firstID, 
                                                int maxCount, 
                                                double happinessGoal, 
                                                Resident::Color color) override;
        std::string toString () override;
    
    private:
        /*  Prompts for how many residents in this group. Prompts aren't complete.
            Need to have the maximum number of residents allowed.   */
        std::string _howManyOrigPrompt  = 
            "How many \"Flat Residents\" should there be? Must be less than ";
        std::string _howManyTypePrompt  =
            "Nope, that's not a whole number. Should be a number without any"
            " decimals.";
        std::string _howManyRangePrompt = 
            "That number is too small or too large. Should be between 1 and ";

        /*  Prompts for the happiness goal for this group of residents. */
        std::string _happinessGoalOrigPrompt  = 
            "What should the happiness goal of these residents?  Must be a number"
            " between 0 and 1 inclusively.";
        std::string _happinessGoalTypePrompt  = 
            "Nope, that's not a number, i.e. 0.2 or 1.0";
        std::string _happinessGoalRangePrompt = 
            "That number is too small or too large. Should be between 0.0 and 1.0"
            " inclusive.";
                                        
        /*  Prompts for the allowed movement for this group of residents.   */
        std::string _movmentOrigPrompt  = 
            "When these residents move, how far away can their new house be from"
            "their  original house? Must be a positive number.";
        std::string _movementTypePrompt  = 
            "Nope, that's not a number, i.e. 0.2 or 13.0";
        std::string _movemenRangePrompt = 
            "That number is not positive. It must be 0.0 or greater.";
                                        
        /*  Prompts for the Happiness Value when the Diversity is zero for 
            this group of residents.    */
        std::string _happinessValueOrigPrompt  = 
            "\"Flat Residents\" always have the same happiness value"
            " regardless of the diversity of their neighbors. Enter the happiness"
            " value for this group of \"Flat Residents\".  The happiness value"
            " must be between 0.0 and 1.0 inclusive.";
        std::string _happinessValueTypePrompt  = 
            "Nope, that's not a number, i.e. 0.2 or 1.0";
        std::string _happinessValueRangePrompt = 
            "That number is too small or too large. Should be between 0.0 and 1.0"
            " inclusive.";

        int askUserForInt (UI& ui,
                           Question_Int question, 
                           std::string failureString);
        double askUserForDouble (UI& ui,
                                 Question_Double question, 
                                 std::string failureString);
};

#endif