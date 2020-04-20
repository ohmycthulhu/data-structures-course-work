#include <iostream>
#include <stdio.h>
#include <string.h>
#include <limits>
#include <regex>

using namespace std;

void printVariable (const char* msg, char c) {
    cout    << msg
            << (int)c
            << " ( "
            << c
            << " ) "
            << endl;
}

int char_io() {
    char cC1, cC2;

    // C style input and output
    printf("Input character: ");
    // First option with scanf
    scanf("%c", &cC1);
    printf("You inputted character: %c\n", cC1);

    // Clear input buffer
    while (getchar() != '\n');

    printf("Input another character: ");
    // Second option for reading
    cC2 = getchar();
    printf("The second character is: %c\n", cC2);


    // C++ style input and output
    cout << "Input the third character: ";

    char cCpp;
    // Input character via C++ functions
    cin >> cCpp;
    cout << "The third character is " << cCpp <<  endl;

    return 0;
}

int char_cast() {
    char c(0x41);       // Initializing variable

    cout    << "Symbol is "
            << c        // Output the corresponding symbol
            << endl
            << "Code of symbol (in hex) is "
            << hex      // Set output to hex mode
            << (int)c   // Output the value of c
            << endl;

    return 0;
}

int char_arithmetic() {
    // Initializing variables
    const char first(0x48), second(0x41);
    char result;

    // Display initial values
    printVariable("First char is ", first);
    printVariable("Second char is ", second);

    // Sum operation
    result = first + second;
    printVariable("Sum result is ", result);

    // Subtract operation
    result = first - second;
    printVariable("Subtraction result is ", result);

    // Several comparisons
    bool isGreater = first > second,
         isLess = first < second,
         areEqual = first == second;

    cout << boolalpha; // Set cout to show true or false for boolean
    cout    << "Is first greater? "
            << isGreater
            << endl
            << "Is first less? "
            << isLess
            << endl
            << "Are they equal? "
            << areEqual
            << endl;

    // Cyclic shifts
    result = first << 1;
    printVariable("Shift to left by 1 is ", result);
    result = first >> 2;
    printVariable("Shift to right by 2 is ", result);

    return 0;
}

int char_case() {
    // Input character
    cout << "Input character: ";
    char c;
    cin >> c;

    cout << boolalpha; // Set cout to print true/false

    // Check the case
    cout    << "Is symbol in lower case? "
            << (bool)islower(c)
            << endl
            << "Is symbol in upper case? "
            << (bool)isupper(c)
            << endl;

    cout    << "Your character in upper case is "
            << (char)toupper(c)
            << endl
            << "Your character in lower case is "
            << (char)tolower(c)
            << endl;

    return 0;
}

int char_check() {
    // Input character
    cout << "Input character: ";
    char c;
    cin >> c;

    cout << boolalpha; // Set cout to print true/false

    // Check the case
    cout    << "Is symbol a letter? "
            << (bool)isalpha(c)
            << endl
            << "Is symbol a digit? "
            << (bool)isdigit(c)
            << endl
            << "Is symbol a digit or number? "
            << (bool)isalnum(c)
            << endl;


    return 0;
}

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

int regex_example() {
    // Regular expressions for searching
    regex   regEmail("[\\w\\d]+\\@\\w+\\.\\w{2,}"),
            regPhone("(\\+\\d{1,3})?(\\d{2,3})?\\d{7}");

    // Input strings
    string str;

    cout << "Input the string: ";
    getline(cin, str);

    // Match object for storing matches
    smatch m;

    string matchEmail = "Email not found";
    if (regex_search(str, m, regEmail)) {
        matchEmail = m.str();
    }


    string matchPhone = "Phone not found";
    if (regex_search(str, m, regPhone)) {
        matchPhone = m.str();
    }

    // Output results
    cout    << "The string is " << str << endl
            << "Email: " << matchEmail << endl
            << "Phone: " << matchPhone << endl;

    return 0;
}
