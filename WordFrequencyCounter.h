#ifndef WORD_FREQUENCY_COUNTER_H
#define WORD_FREQUENCY_COUNTER_H

#include <map>
#include <string>

class WordFrequencyCounter {
private:
    std::map<std::string, int> wordFrequency;

public:
    WordFrequencyCounter(); 

    void processText(const std::string& filename);
    void displayWordFrequency() const;
    std::string mostFrequentWord() const;
    void writeToFile(const std::string& filename) const;
};

#endif
