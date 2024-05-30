#include "ItemDeliveryQuest.h"
#include <iostream>

using namespace std;

ItemDeliveryQuest::ItemDeliveryQuest(int reward, int goldReward, int itemLocation, int clientLocation, int itemID)
    : Quest(reward), goldReward(goldReward), itemLocation(itemLocation), clientLocation(clientLocation), itemID(itemID) {}

ItemDeliveryQuest::~ItemDeliveryQuest() {}

void ItemDeliveryQuest::displayInfo() const {
    cout << "Quest Type: Item Delivery\n";
    cout << "Reward: " << getReward() << " gold\n";
    cout << "Gold Reward: " << goldReward << " gold\n";
    cout << "Item Location: " << itemLocation << "\n";
    cout << "Client Location: " << clientLocation << "\n";
    cout << "Item ID: " << itemID << "\n";
}

int ItemDeliveryQuest::getGoldReward() const {
    return goldReward;
}

int ItemDeliveryQuest::getItemLocation() const {
    return itemLocation;
}

int ItemDeliveryQuest::getClientLocation() const {
    return clientLocation;
}

int ItemDeliveryQuest::getItemID() const {
    return itemID;
}

void ItemDeliveryQuest::setGoldReward(int goldReward) {
    this->goldReward = goldReward;
}

void ItemDeliveryQuest::setItemLocation(int itemLocation) {
    this->itemLocation = itemLocation;
}

void ItemDeliveryQuest::setClientLocation(int clientLocation) {
    this->clientLocation = clientLocation;
}

void ItemDeliveryQuest::setItemID(int itemID) {
    this->itemID = itemID;
}