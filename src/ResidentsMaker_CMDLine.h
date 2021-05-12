#ifndef RESIDENTSMAKER_CMDLINE_H
#define RESIDENTSMAKER_CMDLINE_H

#include "ResidentsMaker.h"
#include "Question_Int.h"

class ResidentsMaker_CMDLine: public ResidentsMaker
{
    public:
        ResidentsMaker_CMDLine ();
        ~ResidentsMaker_CMDLine () = default;
        std::vector<std::unique_ptr<Resident>> 
            makeResidents (std::vector<ResidentsFactory*> residentsFactories,
                           int maxNumOfResidents) override;
    private:
        std::vector<std::string> getNames (std::vector<ResidentsFactory*> residentsFactories);
        int getNumberOfTypesOfResidents(UI& ui);
        Question_Int createQuestionHowManyResidentTypes();
        std::unique_ptr<Resident> makeResidents(UI& ui, int maxNumOfResidents);

};

#endif