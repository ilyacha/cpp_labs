#include "CaravanRouteQuest.h"
#include <iostream>

using namespace std;

CaravanRouteQuest::CaravanRouteQuest(int reward, int startLocation, int endLocation, long long int deadline)
    : Quest(reward), startLocation(startLocation), endLocation(endLocation), deadline(deadline) {}

CaravanRouteQuest::~CaravanRouteQuest() {}

void CaravanRouteQuest::displayInfo() const {
    cout << "Quest Type: Caravan Route\n";
    cout << "Reward: " << getReward() << " gold\n";
    cout << "Start Location: " << startLocation << "\n";
    cout << "End Location: " << endLocation << "\n";
    cout << "Deadline: " << deadline << "\n";
}

int CaravanRouteQuest::getStartLocation() const
{
    return startLocation;
}

int CaravanRouteQuest::getEndLocation() const
{
    return endLocation;
}

int CaravanRouteQuest::getDeadline() const
{
    return deadline;
}

void CaravanRouteQuest::setStartLocation(int startLocation)
{
    this->startLocation = startLocation;
}

void CaravanRouteQuest::setEndLocation(int endLocation)
{
    this->endLocation = endLocation;
}

void CaravanRouteQuest::setDeadline(int deadline)
{
    this->deadline = deadline;
}
