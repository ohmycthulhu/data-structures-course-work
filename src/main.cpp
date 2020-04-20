#include <iostream>
#include <string.h>
#include <regex>

using namespace std;

// Input functions
bool validateString(const string& str, const size_t minSize);

string getString(const string& msg, const size_t minSize);

// Basic operations functions
// Void is returned, when calculated result don't match with standard result
bool getStringLength(const string& str, size_t* result);

bool searchInString(const string& str, const char c, size_t* result);
bool searchInString(const string& str, const string &subStr, size_t* result);

bool getSubstring(const string& str, string* result, const size_t startPos = 0, const size_t length = string::npos);

bool concatStrings(const string& str1, const string& str2, string* result);

bool insertString(const string& dest, const string& source, string* result, const size_t index = 0);

// Regexp function
void getRegexMatches(const string& str, string *resEmail, string *resPhone, string *resWebsite);

// Output functions
void showError(const char* error);

template<typename T, typename... Args>
void _showMsg(T msg, Args ...anotherMsgs);
void _showMsg();

template<typename... Args>
void showMsg(Args... msgs);

int main() {
    /*
        Constants
    */

    const size_t insPosition = 3;
    const size_t insSize = 5;
    const size_t minMainSize = 5;
    const size_t minAdditionalSize = 3;
    const string msgMain = "Input main string: ";
    const string msgAdditional = "Input additional string: ";
    const char charToFind = 'f';
    const string strToFind = "find";

    /*
        Input section
    */

    // Get string from input
    string strMain = getString(msgMain, minMainSize);
    string strAdd = getString(msgAdditional, minAdditionalSize);

    /*
        </Input section>
    */


    /*
        <Operation section>
    */

    bool funcResult;
    size_t strMainLen, strAddLen;
    // Check string length
    funcResult = getStringLength(strMain, &strMainLen);
    if (funcResult) {
        showMsg("Length of main string is ", strMainLen);
    } else {
        showError("Length of the main string is invalid");
    }

    funcResult = getStringLength(strAdd, &strAddLen);

    if (funcResult) {
        showMsg("Length of additional string is ", strAddLen);
    } else {
        showError("Length of the additional string is invalid");
    }

    // Search for symbols and substring
    size_t charPos, subStrPos;
    funcResult = searchInString(strMain, charToFind, &charPos);

    if (funcResult) {
        showMsg("Character is in index ", charPos);
    } else {
        showError("Couldn't find correctly find the position of char");
    }

    funcResult = searchInString(strMain, strToFind, &subStrPos);

    if (funcResult) {
        showMsg("Substring is in index ", subStrPos);
    } else {
        showError("Couldn't find correctly find the position of substring");
    }

    // Get substring
    string subStrResult;
    funcResult = getSubstring(strMain, &subStrResult, insPosition, insSize);

    if (funcResult) {
        showMsg("Substring from ", insPosition, " with length of ", insSize, " is ", subStrResult);
    } else {
        showError("Couldn't find correctly extract substring");
    }

    // Concatenate strings
    string concatResult;
    funcResult = concatStrings(strMain, strAdd, &concatResult);

    if (funcResult) {
        showMsg("Concat result is ", concatResult);
    } else {
        showError("Couldn't find correctly concatenate strings");
    }

    // Insert substring
    string insResult;
    funcResult = insertString(strMain, strAdd, &concatResult, insPosition);

    if (funcResult) {
        showMsg("Insert result for ", insPosition ," index is ", concatResult);
    } else {
        showError("Couldn't find correctly insert additional string into main");
    }

    // Get email, phone and website from main string
    string emailMatch, phoneMatch, webSiteMatch;
    getRegexMatches(strMain, &emailMatch, &phoneMatch, &webSiteMatch);

    /*
        </Operation section>
    */

    /*
        <Output section>
    */

    // Show the regexp search result
    showMsg("Inputted phone is ", phoneMatch);
    showMsg("Inputted email is ", emailMatch);
    showMsg("Inputted website is ", webSiteMatch);

    /*
        </Output section>
    */

}

void showError(const char* msg) {
    cout << "********** Error **********" << endl;
    cout << msg << endl;
    cout << "***************************" << endl << endl;
}

template<typename... Args>
void showMsg(Args... msgs) {
    cout << "********** Message **********" << endl;

    _showMsg(msgs...);

    cout << endl;

    cout << "*****************************" << endl << endl;
}

template<typename T, typename... Args>
void _showMsg(T msg, Args ...anotherMsgs) {
    cout << msg;

    _showMsg(anotherMsgs...);
}

void _showMsg() {
}

bool validateString(const string& str, const size_t minSize) {
    return str.size() >= minSize;
}

string getString(const string& msg, const size_t minSize) {
    string res;
    do {
        cout << msg;
        getline(cin, res);
    } while(!validateString(res, minSize));
    return res;
}

bool getStringLength(const string& str, size_t* result) {
    const char* ptr = str.c_str();

    size_t resCalc = 0;
    while (ptr[resCalc] != '\0') { resCalc++; }

    size_t resReal = str.size();

    if (resReal != resCalc) {
        return false;
    }

    if (result != nullptr) {
        *result = resCalc;
    }
    return true;
}

bool searchInString(const string& str, const char c, size_t* result){
    size_t resCalc = string::npos;

    size_t strSize = str.size();
    // Search for the character
    for (size_t i = 0; i < strSize; i++) {
        // Check current character
        if (str[i] == c) {
            resCalc = i;
            break;
        }
    }

    size_t resReal = str.find(c);

    if (resCalc != resReal) {
        return false;
    }

    if (result != nullptr) {
        *result = resCalc;
    }
    return true;
}
bool searchInString(const string& str, const string &subStr, size_t* result){
    size_t resCalc = string::npos;

    size_t strSize = str.size();
    size_t subStrSize = subStr.size();

    // Search for the character
    for (size_t i = 0, subStrIndex = 0; i < strSize; i++) {
        if (str[i] == subStr[subStrIndex]) {
        // If position is not found yet
            if (resCalc == string::npos) {
                resCalc = i;
            }
            subStrIndex++;
            if (subStrIndex >= subStrSize) {
                break;
            }
        } else {
            subStrIndex = 0;
            resCalc = string::npos;
        }
    }

    size_t resReal = str.find(subStr);

    if (resCalc != resReal) {
        return false;
    }

    if (result != nullptr) {
        *result = resCalc;
    }
    return true;
}

bool getSubstring(const string& str, string* result, const size_t startPos, const size_t subStrLen) {
    string resCalc = "";
    size_t strLen = str.size();

    for (int i = startPos; i < strLen && resCalc.size() < subStrLen; i++) {
        resCalc += str[i];
    }

    string resReal = str.substr(startPos, subStrLen);

    if (resCalc != resReal) {
        return false;
    }

    if (result != nullptr) {
        *result = resCalc;
    }
    return true;
}

bool concatStrings(const string& str1, const string& str2, string* result) {

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

    string resReal = str1 + str2;
    if (resCalc != resReal) {
        return false;
    }

    if (result != nullptr) {
        *result = resCalc;
    }
    return true;
}
bool insertString(const string& str1, const string& str2, string* result, const size_t index) {

    const char *str1Ptr = str1.c_str(),
               *str2Ptr = str2.c_str();

    size_t  str1Size = strlen(str1Ptr),
            str2Size = strlen(str2Ptr);

    char * strResPtr = new char[str1Size + str2Size + 1];
    strResPtr[str1Size + str2Size] = '\0';

    size_t offset = 0;
    // Copy the first string
    for (int i = 0; i < str1Size; i++) {
        if (i == index) {
            for (int j = 0; j < str2Size; j++) {
                strResPtr[i + j] = str2Ptr[j];
            }
            offset = str2Size;
        }
        strResPtr[offset + i] = str1Ptr[i];
    }

    string resCalc(strResPtr);

    string resReal = str1;
    resReal.insert(index, str2);

    if (resCalc != resReal) {
        return false;
    }

    if (result != nullptr) {
        *result = resCalc;
    }
    return true;
}

void getRegexMatches(const string& str, string *resEmail, string *resPhone, string *resWebsite) {
    // Regular expressions for searching
    regex   regEmail("[\\w\\d]+\\@\\w+\\.\\w{2,}"),
            regPhone("(\\+\\d{1,3})?(\\d{2,3})?\\d{7}"),
            regWebsite("(https?:\\/\\/)?[\\w\\d\\.\\_\\-]+\\.[\\w\\d\\.\\_\\-]+");

    smatch m;

    if (resEmail != nullptr) {
        if (regex_search(str, m, regEmail)) {
            *resEmail = m.str();
        } else {
            *resEmail = "Not found";
        }
    }

    if (resPhone != nullptr) {
        if (regex_search(str, m, regPhone)) {
            *resPhone = m.str();
        } else {
            *resPhone = "Not found";
        }
    }

    if (resWebsite != nullptr) {
        if (regex_search(str, m, regWebsite)) {
            *resWebsite = m.str();
        } else {
            *resWebsite = "Not found";
        }
    }
}
