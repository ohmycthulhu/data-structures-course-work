#include <iostream>
#include <stdio.h>
#include <string.h>
#include <limits>
#include <regex>

using namespace std;

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
