#include "Dictionary.h"
#include <fstream>

Dictionary::Dictionary() {}

void Dictionary::addWord(const std::string& word, const std::string& definition) {
    words[word] = definition;
}

void Dictionary::removeWord(const std::string& word) {
    auto it = words.find(word);
    if (it != words.end()) {
        words.erase(it);
    }
    else {
        std::cout << "Word not found.\n";
    }
}

void Dictionary::editWord(const std::string& word, const std::string& newDefinition) {
    auto it = words.find(word);
    if (it != words.end()) {
        it->second = newDefinition;
    }
    else {
        std::cout << "Word not found.\n";
    }
}

std::string Dictionary::searchWord(const std::string& word) const {
    auto it = words.find(word);
    if (it != words.end()) {
        return it->second;
    }
    else {
        return "Word not found.";
    }
}

void Dictionary::displayAllWords() const {
    for (const auto& entry : words) {
        std::cout << "Word: " << entry.first << "\nDefinition: " << entry.second << "\n\n";
    }
}

void Dictionary::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string word, definition;
        while (file >> word >> std::ws && std::getline(file, definition)) {
            words[word] = definition;
        }
        file.close();
    }
    else {
        std::cerr << "Error opening file: " << filename << "\n";
    }
}

void Dictionary::writeToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& entry : words) {
            file << entry.first << " " << entry.second << "\n";
        }
        file.close();
    }
    else {
        std::cerr << "Error opening file: " << filename << "\n";
    }
}
