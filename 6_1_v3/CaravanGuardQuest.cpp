#include "CaravanGuardQuest.h"
#include <iostream>

using namespace std;

CaravanGuardQuest::CaravanGuardQuest(int reward, int startLocation, int guardCount)
    : Quest(reward), startLocation(startLocation), guardCount(guardCount) {}

CaravanGuardQuest::~CaravanGuardQuest() {}

void CaravanGuardQuest::displayInfo() const {
    cout << "Quest Type: Caravan Guard\n";
    cout << "Reward: " << getReward() << " gold\n";
    cout << "Start Location: " << startLocation << "\n";
    cout << "Guard Count: " << guardCount << "\n";
}

int CaravanGuardQuest::getStartLocation() const
{
    return startLocation;
}

int CaravanGuardQuest::getGuardCount() const
{
    return guardCount;
}

void CaravanGuardQuest::setStartLocation(int startLocation)
{
    this->startLocation = startLocation;
}

void CaravanGuardQuest::setGuardCount(int guardCount)
{
    this->guardCount = guardCount;
}
