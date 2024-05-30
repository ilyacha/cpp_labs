#include "Quest.h"

Quest::Quest(int reward) : reward(reward) {}

Quest::~Quest() {}

int Quest::getReward() const {
    return reward;
}
