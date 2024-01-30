#ifndef TRAIN_H
#define TRAIN_H

#include <string>

class Train {
private:
    int number;
    std::string departureTime;
    std::string destinationStation;

public:
    Train(); 
    Train(int num, const std::string& depTime, const std::string& destStation);

    int getNumber() const;
    std::string getDepartureTime() const;
    std::string getDestinationStation() const;

    void displayInfo() const;
};

#endif
