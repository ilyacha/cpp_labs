#include<iostream>
#include "MonsterHuntQuest.h"
#include "ItemDeliveryQuest.h"
#include "CaravanRouteQuest.h"
#include "CaravanGuardQuest.h"

using namespace std;

int main() {
    MonsterHuntQuest monsterHunt(100, 5, 10, 20, 10);
    ItemDeliveryQuest itemDelivery(200, 8, 15, 42, 10);
    CaravanRouteQuest caravanRoute(300, 3, 25, 1234);
    CaravanGuardQuest caravanGuard(400, 7, 18);

    int choice;
    bool running = true;

    while (running) {
        cout << "- - - - - - - - - -\n";
        cout << "1. Set values\n";
        cout << "2. Get values\n";
        cout << "3. Display first info\n";
        cout << "4. Exit\n";
        cout << "- - - - - - - - - -\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n";

        switch (choice) {
        case 1:
            // Seters
            monsterHunt.setGoldReward(100); // проверки на допустимость в MonsterHuntQuest.cpp
            monsterHunt.setLocationId(200);
            monsterHunt.setMonsterType(111);
            monsterHunt.setMonsterCount(222);

            itemDelivery.setGoldReward(333);
            itemDelivery.setItemLocation(20);
            itemDelivery.setClientLocation(123);
            itemDelivery.setItemID(999);
            
            caravanRoute.setStartLocation(5);
            caravanRoute.setEndLocation(000);
            caravanRoute.setDeadline(987);

            caravanGuard.setGuardCount(22);
            caravanGuard.setStartLocation(432);

            cout << "Values set.\n";
            break;
        case 2:
            // Geters
            cout << "Monster Hunt Gold Reward: " << monsterHunt.getGoldReward() << "\n";
            cout << "Item Delivery Item Location: " << itemDelivery.getItemLocation() << "\n";
            cout << "Caravan Route Start Location: " << caravanRoute.getStartLocation() << "\n";
            cout << "Caravan Guard Count: " << caravanGuard.getGuardCount() << "\n";
            break;
        case 3:
            // Display first info
            monsterHunt.displayInfo();
            cout << "--\n";
            itemDelivery.displayInfo();
            cout << "--\n";
            caravanRoute.displayInfo();
            cout << "--\n";
            caravanGuard.displayInfo();
            break;
        case 4:
            // Exit
            running = false;
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}