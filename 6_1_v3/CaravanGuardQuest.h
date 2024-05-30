#pragma once
#include "Quest.h"

class CaravanGuardQuest : public Quest {
public:
    CaravanGuardQuest(int reward, int startLocation, int guardCount);
    virtual ~CaravanGuardQuest();

    virtual void displayInfo() const override;

    int getStartLocation() const;
    int getGuardCount() const;


    void setStartLocation(int startLocation);
    void setGuardCount(int guardCount);


private:
    int startLocation;
    int guardCount;
};
