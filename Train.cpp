#include "Train.h"
#include <iostream>

Train::Train() : number(0), departureTime(""), destinationStation("") {}

Train::Train(int num, const std::string& depTime, const std::string& destStation)
    : number(num), departureTime(depTime), destinationStation(destStation) {}

int Train::getNumber() const {
    return number;
}

std::string Train::getDepartureTime() const {
    return departureTime;
}

std::string Train::getDestinationStation() const {
    return destinationStation;
}

void Train::displayInfo() const {
    std::cout << "Train Number: " << number << "\n"
        << "Departure Time: " << departureTime << "\n"
        << "Destination Station: " << destinationStation << "\n\n";
}
