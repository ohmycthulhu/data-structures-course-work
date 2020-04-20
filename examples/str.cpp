#include <iostream>
#include <stdio.h>
#include <string.h>
#include <limits>
#include <regex>

using namespace std;

int str_types() {
    char strCnst[] = "This message is constant"; // String with constant length
    string strVar = "This string length can be changed";

    cout    << strCnst
            << "Length of the string is " << strlen(strCnst)
            << endl << endl
            << strVar
            << "Length of this string is " << strVar.size()
            << endl;

    return 0;
}

int str_io() {
    // Input string with cin
    string strCin;
    cout << "Input string via cin: ";
    cin >> strCin;

    // Using this for discarding newline character from the buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Input string with getline
    string strGL;
    cout << "Input string via getline: ";
    getline(cin, strGL);

    // Input with another delimiter getline
    string strGLz;
    cout << "Input string with z as the end of text: ";
    getline(cin, strGLz, 'z');

    // Output with printf. To print the string, it should be casted to const char*
    printf("Your input with cin: %s", strCin.c_str());

    // Output with cout
    cout    << "Your input with getline: " << strGL << endl
            << "Your input another input with geline: " << strGLz << endl;

    return 0;
}

int str_find() {
    // Input string with cin
    string str;
    cout << "Input string: ";
    getline(cin, str);

    // Identify char and string to search
    const char charToFind = 'a';
    const string strToFind = "find";

    // Calculate the real position
    size_t  charLoc = str.find(charToFind),
            strLoc = str.find(strToFind);

    size_t  charLocCalc = string::npos,
            strLocCalc = string::npos;

    // Store sizes to not calculate on each iteration
    size_t  strSize = str.size(),
            strToFindSize = strToFind.size();

    // Search for the character
    for (size_t i = 0; i < strSize; i++) {
        // Check current character
        if (str[i] == charToFind) {
            charLocCalc = i;
            break;
        }
    }

    // Search for the character
    size_t subStrIndex = 0;
    for (size_t i = 0; i < strSize; i++) {
        // Check current character
        if (str[i] == strToFind[subStrIndex]) {
            // If position is not found yet
            if (strLocCalc == string::npos) {
                strLocCalc = i;
            }
            subStrIndex++;
            // Check the end of substring
            if (subStrIndex >= strToFindSize) {
                break;
            }
        } else {
            // Reset the progress on invalid character
            strLocCalc = string::npos;
            subStrIndex = 0;
        }
    }

    // Output results
    cout    << "String is " << str << endl
            << "Real position of character is " << charLoc << endl
            << "Real position of substring is " << strLoc << endl
            << "Calculated position of character is " << charLocCalc << endl
            << "Calculated position of substring is " << strLocCalc << endl;

    return 0;
}

int str_substr() {
    const   size_t  minimalLength = 5,
                    startPos = 3,
                    strLen = 4;

    // Input string with minimal length
    string str;
    do {
        cout << "Input string with minimal length of " << minimalLength << ": ";
        getline(cin, str);
    } while(str.size() < minimalLength);

    string resReal = str.substr(startPos, strLen);
    string resCalc = "";

    for (int i = startPos; i < str.size() && resCalc.size() < strLen; i++) {
        resCalc += str[i];
    }


    // Output results
    cout    << "String is " << str << endl
            << "Result by substr function is " << resReal << endl
            << "Result manually calculated is " << resCalc << endl;

    return 0;
}

int str_concat() {

    // Input strings
    string str1, str2;
    cout << "Input the first string: ";
    getline(cin, str1);
    cout << "Input the second string: ";
    getline(cin, str2);

    // Real result
    string resReal = str1 + str2;

    const char *str1Ptr = str1.c_str(),
               *str2Ptr = str2.c_str();

    size_t  str1Size = strlen(str1Ptr),
            str2Size = strlen(str2Ptr);

    char * strResPtr = new char[str1Size + str2Size + 1];
    strResPtr[str1Size + str2Size] = '\0';

    // Copy the first string
    for (int i = 0; i < str1Size; i++) {
        strResPtr[i] = str1Ptr[i];
    }

    // Copy the second string
    for (int i = 0; i < str2Size; i++) {
        strResPtr[str1Size + i] = str2Ptr[i];
    }

    string resCalc(strResPtr);


    // Output results
    cout    << "The first string is " << str1 << endl
            << "The second string is " << str2 << endl
            << "Result by substr function is " << resReal << endl
            << "Result manually calculated is " << resCalc << endl;

    return 0;
}

int str_ins() {
    const size_t insPosition = 3;

    // Input strings
    string str1, str2;
    do {
        cout << "Input the initial string with minimal length of " << insPosition << ": ";
        getline(cin, str1);
    } while(str1.size() < insPosition);
    cout << "Input string to insert: ";
    getline(cin, str2);

    const char *str1Ptr = str1.c_str(),
               *str2Ptr = str2.c_str();

    size_t  str1Size = strlen(str1Ptr),
            str2Size = strlen(str2Ptr);

    char * strResPtr = new char[str1Size + str2Size + 1];
    strResPtr[str1Size + str2Size] = '\0';

    size_t offset = 0;
    // Copy the first string
    for (int i = 0; i < str1Size; i++) {
        if (i == insPosition) {
            for (int j = 0; j < str2Size; j++) {
                strResPtr[i + j] = str2Ptr[j];
            }
            offset = str2Size;
        }
        strResPtr[offset + i] = str1Ptr[i];
    }

    string resCalc(strResPtr);

    // Real result
    string resReal = str1.insert(insPosition, str2);

    // Output results
    cout    << "The first string is " << str1 << endl
            << "The second string is " << str2 << endl
            << "Result by substr function is " << resReal << endl
            << "Result manually calculated is " << resCalc << endl;

    return 0;
}
