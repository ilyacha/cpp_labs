#include "MonsterHuntQuest.h"
#include <iostream>

using namespace std;

MonsterHuntQuest::MonsterHuntQuest(int reward, int goldReward, int locationId, int monsterType, int monsterCount)
    : Quest(reward), goldReward(goldReward), locationId(locationId), monsterType(monsterType), monsterCount(monsterCount) {}

MonsterHuntQuest::~MonsterHuntQuest() {}

void MonsterHuntQuest::displayInfo() const {
    cout << "Quest Type: Monster Hunt\n";
    cout << "Reward: " << getReward() << " gold\n";
    cout << "Gold Reward: " << getGoldReward() << " gold\n";
    cout << "Location ID: " << locationId << "\n";
    cout << "Monster Type: " << monsterType << "\n";
    cout << "Monster Count: " << monsterCount << "\n";
}

int MonsterHuntQuest::getGoldReward() const {
    return goldReward;
}

int MonsterHuntQuest::getLocationId() const {
    return locationId;
}

int MonsterHuntQuest::getMonsterType() const {
    return monsterType;
}

int MonsterHuntQuest::getMonsterCount() const {
    return monsterCount;
}

bool running_1 = true;

void MonsterHuntQuest::setGoldReward(int goldReward) {
    if (goldReward < 1 || goldReward > 10001) {
        cerr << "Error: Gold Reward must be between 1 and 10000";
    }
    this->goldReward = goldReward;
}

void MonsterHuntQuest::setLocationId(int locationId) {
    if (locationId < 1 || locationId > 10001) {
        cerr << "Error: Location Id must be between 1 and 10000";
    }
    this->locationId = locationId;
}

void MonsterHuntQuest::setMonsterType(int monsterType) {
    if (monsterType < 1 || monsterType > 10001) {
        cerr << "Error: Monster Type must be between 1 and 10000";
    }
    this->monsterType = monsterType;
}

void MonsterHuntQuest::setMonsterCount(int monsterCount) {
    if (monsterCount < 1 || monsterCount > 10001) {
        cerr << "Error: Monster Count must be between 1 and 10000";
    }
    this->monsterCount = monsterCount;
}