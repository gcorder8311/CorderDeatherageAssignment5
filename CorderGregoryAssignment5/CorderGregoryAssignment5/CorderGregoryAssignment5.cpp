/*
This is assignment 5 for CSC 242 at National University
This assignment is designed to encrypt or decrypt a file based on a keyword using monoalphabet cypher.
This is Greg Corder's part of the final assignment with Thomas Deatherage
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

//Greg Corder
string removeDuplicates(const string& keyword) //sets the keyword to a constant to ensure it doesn't change
{
    string result = "";
    for (char c : keyword) //checks each character in the string
    {
        if (result.find(c) == string::npos) //checks if the character is already in the cleaned up keyword and removes duplicates
        {
            result += c; 
        }
    }
    return result;
}

//Greg Corder
string buildcypherAlphabet(const string& keyword) //builds the cypher based on keyword
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //references alphabet
    string cypher = keyword;

    for (int i = alphabet.size() - 1; i >= 0; i--)  // reverses the alphabet 
    {
        if (cypher.find(alphabet[i]) == string::npos) //adds letter if not in keyword
        {
            cypher += alphabet[i];
        }
    }
    return cypher;
}

//Greg Corder
int main() 
{
    string keyword, fileIn, fileOut; //set the strings and character needed for problem
    char mode;

    cout << "Enter mode (e = encrypt, d = decrypt): "; //user enters encryption or decryption
    cin >> mode;

    cout << "Enter keyword: "; //user enters keyword
    cin >> keyword;

    cout << "Enter input file (\"TestFile.txt\" can be used for encryption): "; //chooses input file
    cin >> fileIn;

    cout << "Enter output file (Make sure to remember your file name if you want to decrypt it later): "; //chooses output file
    cin >> fileOut;

    if (keyword.empty()) //escapes if no keyword
    {
        cout << "Error: Keyword is required.\n";
        return 1;
    }

    for (char& c : keyword) //changes all keyword characters to uppercase to meet cypher in alphabet standard in line 27
    {
        c = toupper(c);
    }

    keyword = removeDuplicates(keyword);

    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    string cypherAlphabet = buildcypherAlphabet(keyword); //applies my keyword cypher function to to the alphabet

    ifstream inFile(fileIn); //inports file
    ofstream outFile(fileOut); //exports file

    if (!inFile) 
    {
        cout << "Error opening input file.\n"; //escapes if file name incorrect
        return 1;
    }

    char ch; //this whole section checks upper and lower case and replaces each character in the file with the cypher character
    while (inFile.get(ch)) 
    {
        if (isalpha(ch)) //ignors punctuation
        {
            bool isLower = islower(ch); //stores if lower case for reverting later
            char upperChar = toupper(ch);

            int index;
            if (mode == 'e') //processes replacement with cypherAlphabet if encrypting
            {
                index = alphabet.find(upperChar);
                ch = cypherAlphabet[index];
            }
            else if (mode == 'd') 
            {
                index = cypherAlphabet.find(upperChar); //processes replacement with normal alphabet if decrypting
                ch = alphabet[index];
            }

            if (isLower) //reverts back to lowercase if needed
            {
                ch = tolower(ch);
            }
        }

        outFile.put(ch); 
    }

    inFile.close(); //exits the files so they can be opened by user after
    outFile.close();

    cout << "Your file has been encrypted or decrypted.\n"; //tells the user the process is done

    return 0; //exits
}