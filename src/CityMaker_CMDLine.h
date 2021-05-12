#ifndef CITYMAKER_CMDLINE_H
#define CITYMAKER_CMDLINE_H

#include "CityMaker.h"

class CityMaker_CMDLine: public CityMaker
{
    public:
        std::unique_ptr<City> makeCity (std::vector<CityFactory*> cityFactories) const override;
        
};

#endif