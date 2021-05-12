#include "ResidentsFactory_Flat.h"
#include <limits>
#include "Resident_Flat.h"

std::string ResidentsFactory_Flat::toString ()
{
    return "Flat Residents Factory";
}

std::vector<std::unique_ptr<Resident>> ResidentsFactory_Flat::createResidents (
                                                            UI& ui, 
                                                            int firstID,
                                                            int maxCount,
                                                            Resident::Color color)
{   
    Question_Double qHappinessGoal{1,
                                   0.0,
                                   1.0,
                                   _happinessGoalOrigPrompt,
                                   _happinessGoalTypePrompt,
                                   _happinessGoalRangePrompt};

    double happinessGoal = askUserForDouble(ui,
                                            qHappinessGoal,
                                            "Can not get information needed to"
                                            " determine the happiness goal for"
                                            " these residents from the user.");
    
    return createResidents(ui, firstID, maxCount, happinessGoal, color);
}

std::vector<std::unique_ptr<Resident>> ResidentsFactory_Flat::createResidents (
                                                            UI& ui,
                                                            int firstID, 
                                                            int maxCount, 
                                                            double happinessGoal, 
                                                            Resident::Color color)
{   
    Question_Int qHowMany{0,
                          1,
                          maxCount,
                          _howManyOrigPrompt + std::to_string(maxCount) + ".",
                          _howManyTypePrompt,
                          _howManyRangePrompt + std::to_string(maxCount) + "."};

    Question_Double qMovement{2,
                              0.0,
                              std::numeric_limits<double>::max(),
                              _movmentOrigPrompt,
                              _movementTypePrompt,
                              _movemenRangePrompt};

    Question_Double qHappinessValue{3,
                                     0.0,
                                     1.0,
                                     _happinessValueOrigPrompt,
                                     _happinessValueTypePrompt,
                                     _happinessValueRangePrompt};

    int howMany = askUserForInt(ui,
                                qHowMany, 
                                "Can not get information needed to determine"
                                " number of residents from the user.");
    
    double movement = askUserForDouble(ui,
                                       qMovement,
                                       "Can not get information needed to"
                                       " determine the allowed movement for these"
                                       " residents from the user.");

    double happinessValue = askUserForDouble(ui,
                                             qHappinessValue,
                                             "Can not get information needed to"
                                             " determine the happiness value for"
                                             " these residents from the user.");

    std::vector<std::unique_ptr<Resident>> residents = {};
    for ( int ii=0; ii<howMany; ++ii)
    {
        residents.push_back(
            std::make_unique<Resident_Flat>(firstID+ii,
                                            color,
                                            Resident::ResidentType::flat,
                                            movement,
                                            happinessGoal,
                                            happinessValue));
    }
    return residents;
}

int ResidentsFactory_Flat::askUserForInt (UI& ui, 
                                              Question_Int question, 
                                              std::string failureString)
{
    ui.getAnswer(question);
    if (question.hasValidAnswer())
    {
        return std::stoi(question.getAnswer());
    }
    else
    {
        throw failureString;
    }
}

double ResidentsFactory_Flat::askUserForDouble (UI& ui, 
                                                 Question_Double question, 
                                                 std::string failureString)
{
    ui.getAnswer(question);
    if (question.hasValidAnswer())
    {
        return std::stod(question.getAnswer());
    }
    else
    {
        throw failureString;
    }
}
