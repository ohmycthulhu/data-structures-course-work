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