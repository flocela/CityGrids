#include "ResidentsMaker_CMDLine.h"
#include "UI_CMDLine.h"

ResidentsMaker_CMDLine::ResidentsMaker_CMDLine ()
{}

std::vector<std::unique_ptr<Resident>> ResidentsMaker_CMDLine
    ::makeResidents ( std::vector<ResidentsFactory*> residentsFactories,
                                                     int maxNumOfResidents )
{
    UI_CMDLine ui{};
    int numOfTypesOfResidents = getNumberOfTypesOfResidents(ui);
    
    std::vector<std::unique_ptr<Resident>> residents;
    std::vector<std::string> factoryNames = getNames(residentsFactories);
    int numOfResidentsCreated = 0;
    for (int ii=0; ii<numOfTypesOfResidents; ++ii)
    {
        int choice = ui.menu("Choose a resident type by typing the corresponding"
                             " number.",
                             factoryNames );
        int numResidentsLeftToMake = maxNumOfResidents - numOfResidentsCreated;
        auto newResidents = 
                residentsFactories[choice]->createResidents(ui,
                                                            numOfResidentsCreated,
                                                            numResidentsLeftToMake,
                                                            .5,
                                                            Resident::Color::green);
        for (auto& r: newResidents)
        {
            residents.emplace_back(std::move(r));
        }
    }
    
    return residents;
}

int ResidentsMaker_CMDLine::getNumberOfTypesOfResidents(UI& ui)
{
    Question_Int question = createQuestionHowManyResidentTypes();
    ui.getAnswer(question);
    if (question.hasValidAnswer())
        return std::stoi(question.getAnswer());
    else
        throw "Could not determine how many resident types the user wanted.";
}

std::vector<std::string> ResidentsMaker_CMDLine::getNames (
                        std::vector<ResidentsFactory*> residentsFactories)
{
    std::vector<std::string> residentsFactoryNames = {};
    for (ResidentsFactory* residentFactory: residentsFactories)
    {
        residentsFactoryNames.push_back(residentFactory->toString());
    }
    return residentsFactoryNames;
}

Question_Int ResidentsMaker_CMDLine::createQuestionHowManyResidentTypes()
{
    return Question_Int{0,
                        1,
                        3, 
                        "How many different types of residents will there be? 1,"
                        " 2, or 3?",
                        "Nope that's not a whole number.  Should be 1, 2, or 3."
                        " No, decimals.",
                        "That's either too small or too large. Should be 1, 2,"
                        " or 3."};
}