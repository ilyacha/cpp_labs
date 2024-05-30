#pragma once
#include "Quest.h"

class ItemDeliveryQuest : public Quest {
public:
    ItemDeliveryQuest(int reward, int goldReward, int itemLocation, int clientLocation, int itemID);
    virtual ~ItemDeliveryQuest();

    virtual void displayInfo() const override;

    int getGoldReward() const;
    int getItemLocation() const;
    int getClientLocation() const;
    int getItemID() const;

    void setGoldReward(int goldReward);
    void setItemLocation(int itemLocation);
    void setClientLocation(int clientLocation);
    void setItemID(int itemID);

private:
    int goldReward;
    int itemLocation;
    int clientLocation;
    int itemID;
};