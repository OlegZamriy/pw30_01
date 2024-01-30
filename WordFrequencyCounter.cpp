#include "WordFrequencyCounter.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

WordFrequencyCounter::WordFrequencyCounter() {}

void WordFrequencyCounter::processText(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string word;
        while (file >> word) {
            word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);

            wordFrequency[word]++;
        }
        file.close();
    }
    else {
        std::cerr << "Error opening file: " << filename << "\n";
    }
}

void WordFrequencyCounter::displayWordFrequency() const {
    for (const auto& entry : wordFrequency) {
        std::cout << "Word: " << entry.first << "\tFrequency: " << entry.second << "\n";
    }
}

std::string WordFrequencyCounter::mostFrequentWord() const {
    auto maxFrequencyWord = std::max_element(
        wordFrequency.begin(), wordFrequency.end(),
        [](const auto& a, const auto& b) { return a.second < b.second; });

    return (maxFrequencyWord != wordFrequency.end()) ? maxFrequencyWord->first : "";
}

void WordFrequencyCounter::writeToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& entry : wordFrequency) {
            file << entry.first << "\t" << entry.second << "\n";
        }
        file.close();
    }
    else {
        std::cerr << "Error opening file: " << filename << "\n";
    }
}
