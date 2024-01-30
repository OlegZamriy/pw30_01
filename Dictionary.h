#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <map>
#include <string>

class Dictionary {
private:
    std::map<std::string, std::string> words;

public:
    Dictionary();

    void addWord(const std::string& word, const std::string& definition);
    void removeWord(const std::string& word);
    void editWord(const std::string& word, const std::string& newDefinition);
    std::string searchWord(const std::string& word) const;

    void displayAllWords() const;
    void readFromFile(const std::string& filename);
    void writeToFile(const std::string& filename) const;
};

#endif
