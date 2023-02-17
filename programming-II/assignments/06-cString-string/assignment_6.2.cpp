//*****************************************************************************************************
//
//		This program takes a string and uses various string functions to extract and display
//      information about the string such as the length, number of letters, digits, upper and lower
//      case letters, specific characters and indexes of certain characters.
//
//*****************************************************************************************************

#include <cctype>
#include <cctype>     // c standard library contains functions for character classification: isalpha(), isdigit(), islower(), isupper(), etc.
#include <iostream>
#include <string>
using namespace std;

//*****************************************************************************************************

void sentenceData(const string sentence);

//*****************************************************************************************************

int main() {
    string sentence("This is a 101 SAMPLE to demonstrate string processing");

    cout << "------------------------------------------------------ \n"
         << sentence << "\n"
         << "------------------------------------------------------" << endl;
    sentenceData(sentence);

    return 0;
}

//*****************************************************************************************************

void sentenceData(const string sentence) {
    int length = sentence.length(),     // length() returns the length of the string (number of characters)
        alphaCount = 0,
        digitCount = 0,
        lowerCount = 0,
        upperCount = 0,
        first_s = sentence.find('s'),                   // find() returns the index of the first occurrence of a character (or string)
        second_s = sentence.find('s', first_s + 1);     // find(char, index)

    for (int i = 0; i < length; ++i) {
        if (isalpha(sentence[i]))     // isalpha() checks if a character is a letter
            alphaCount++;
        if (isdigit(sentence[i]))     // isdigit() checks if a character is a digit
            digitCount++;
        if (islower(sentence[i]))     // islower() checks if a character is a lower case letter
            lowerCount++;
        if (isupper(sentence[i]))     // isupper() checks if a character is an upper case letter
            upperCount++;
    }

    cout << "The size of the string: " << length << "\n"
         << "The number of letters in the string: " << alphaCount << "\n"
         << "The number of digits in the string: " << digitCount << "\n"
         << "The number of lower case letters in the string: " << lowerCount << "\n"
         << "The number of upper case letters in the string: " << upperCount << "\n"
         << "The character that is at index 12 of the string: " << sentence.at(12) << "\n"
         << "The first character of the string: " << sentence.front() << "\n"
         << "The last character of the string: " << sentence.back() << "\n"
         << "The index of the first 's' in the string: " << first_s << "\n"
         << "The index of the second 's' in the string: " << second_s << endl;
}

//*****************************************************************************************************

/*

------------------------------------------------------
This is a 101 SAMPLE to demonstrate string processing
------------------------------------------------------
The size of the string: 53
The number of letters in the string: 42
The number of digits in the string: 3
The number of lower case letters in the string: 35
The number of upper case letters in the string: 7
The character that is at index 12 of the string: 1
The last character of the string: g
The index of the first 's' in the string: 3
The index of the second 's' in the string: 6

*/