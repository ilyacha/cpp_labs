#pragma once
#include "Quest.h"

class MonsterHuntQuest : public Quest {
public:
    MonsterHuntQuest(int reward, int goldReward, int locationId, int monsterType, int monsterCount);
    virtual ~MonsterHuntQuest();

    virtual void displayInfo() const override;

    int getGoldReward() const;
    int getLocationId() const;
    int getMonsterType() const;
    int getMonsterCount() const;

    void setGoldReward(int goldReward);
    void setLocationId(int locationId);
    void setMonsterType(int monsterType);
    void setMonsterCount(int monsterCount);

private:
    int goldReward;
    int locationId;
    int monsterType;
    int monsterCount;
};