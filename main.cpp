#include "Dictionary.h"
#include <iostream>

int main() {
    Dictionary dictionary;

    dictionary.addWord("apple", "a round fruit with red or green skin and a whitish interior");
    dictionary.addWord("computer", "an electronic device for storing and processing data");


    dictionary.displayAllWords();

    std::string searchWord;
    std::cout << "Enter a word to search: ";
    std::cin >> searchWord;
    std::cout << dictionary.searchWord(searchWord) << "\n";

    std::string wordToRemove;
    std::cout << "Enter a word to remove: ";
    std::cin >> wordToRemove;
    dictionary.removeWord(wordToRemove);

    std::string wordToEdit, newDefinition;
    std::cout << "Enter a word to edit: ";
    std::cin >> wordToEdit;
    std::cout << "Enter the new definition: ";
    std::cin.ignore(); 
    std::getline(std::cin, newDefinition);
    dictionary.editWord(wordToEdit, newDefinition);

    dictionary.writeToFile("dictionary.txt");
    Dictionary newDictionary;
    newDictionary.readFromFile("dictionary.txt");

    std::cout << "New Dictionary:\n";
    newDictionary.displayAllWords();

    return 0;
}
