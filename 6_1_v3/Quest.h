#pragma once
class Quest {
public:
    Quest(int reward);
    virtual ~Quest();

    virtual void displayInfo() const = 0;
    int getReward() const;

protected:
    int reward;
};