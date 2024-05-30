#pragma once
#include "Quest.h"

class CaravanRouteQuest : public Quest {
public:
    CaravanRouteQuest(int reward, int startLocation, int endLocation, long long int deadline);
    virtual ~CaravanRouteQuest();

    virtual void displayInfo() const override;

    int getStartLocation() const;
    int getEndLocation() const;
    int getDeadline() const;

    void setStartLocation(int startLocation);
    void setEndLocation(int endLocation);
    void setDeadline(int deadline);

private:
    int startLocation;
    int endLocation;
    int deadline;
};
