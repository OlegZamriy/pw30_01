// main.cpp
#include "Train.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Train> trains;

    trains.push_back(Train(101, "08:00", "Kyiv"));
    trains.push_back(Train(202, "10:30", "Lviv"));

    std::cout << "All Trains:\n";
    for (const Train& train : trains) {
        train.displayInfo();
    }

    int queriedTrainNumber;
    std::cout << "Enter the train number to get information: ";
    std::cin >> queriedTrainNumber;

    bool trainFound = false;
    for (const Train& train : trains) {
        if (train.getNumber() == queriedTrainNumber) {
            trainFound = true;
            std::cout << "Information for Train " << queriedTrainNumber << ":\n";
            train.displayInfo();
            break;
        }
    }

    if (!trainFound) {
        std::cout << "Train with number " << queriedTrainNumber << " not found.\n";
    }

    return 0;
}
