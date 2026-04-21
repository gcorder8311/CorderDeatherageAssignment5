/*
Name: Thomas Deatherage
Assignment: Assignment 5 - P8.2 Spell Checker
Role: Person 2
Date: 21 April 2026

Description:
This program reads words from a dictionary file and stores them in a vector.
It then reads words from another file and checks whether each word exists
in the dictionary. If a word is not found, it is printed as a possible
spelling error.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Thomas Deatherage
// Loads all words from the dictionary file into a vector.
void loadDictionary(const string& dictionaryFileName, vector<string>& words)
{
    ifstream dictionaryFile(dictionaryFileName);
    string word;

    if (!dictionaryFile)
    {
        cout << "Error: Could not open dictionary file." << endl;
        return;
    }

    while (dictionaryFile >> word)
    {
        words.push_back(word);
    }
}

// Thomas Deatherage
// Returns true if the target word exists in the dictionary vector.
bool wordExists(const vector<string>& words, const string& target)
{
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] == target)
        {
            return true;
        }
    }

    return false;
}

// Thomas Deatherage
// Reads the file to be checked and prints words not found in the dictionary.
void checkSpelling(const string& inputFileName, const vector<string>& words)
{
    ifstream inputFile(inputFileName);
    string word;

    if (!inputFile)
    {
        cout << "Error: Could not open input file." << endl;
        return;
    }

    cout << "Words not found in dictionary:" << endl;

    while (inputFile >> word)
    {
        if (!wordExists(words, word))
        {
            cout << word << endl;
        }
    }
}

int main()
{
    // Thomas Deatherage
    vector<string> words;

    // Use fixed file names for the dictionary and input file
    string dictionaryFileName = "dictionary.txt";
    string inputFileName = "input.txt";

    loadDictionary(dictionaryFileName, words);
    checkSpelling(inputFileName, words);

    return 0;
}