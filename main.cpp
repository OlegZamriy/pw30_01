#include "WordFrequencyCounter.h"
#include <iostream>

int main() {
    WordFrequencyCounter wordCounter;

    wordCounter.processText("input.txt");

    std::cout << "Word Frequency:\n";
    wordCounter.displayWordFrequency();

    std::cout << "\nMost Frequent Word: " << wordCounter.mostFrequentWord() << "\n";

    wordCounter.writeToFile("word_frequency_output.txt");

    return 0;
}
