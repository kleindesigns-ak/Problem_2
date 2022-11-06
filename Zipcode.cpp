#include "Zipcode.h"

Zipcode::Zipcode() {
    this->zipcode = 00000;
    this->tempPostnetCode = "111000110001100011000110001";
        // Equivalent to 00000 zipcode
}

Zipcode::Zipcode(int zipcode) {
    this->zipcode = zipcode;
}

Zipcode::Zipcode(string postnetCode) {
    this->tempPostnetCode = postnetCode;
    this->postnetCode = postnetCode;
    this->zipcode = convertStringPostnetToIntegerZipcode();
}

/// GETTERS
string Zipcode::getPostnet() {
    return postnetCode;
}

int Zipcode::getZipcode() {
    return zipcode;
}

/// SETTERS
void Zipcode::setPostnet(const string& postnet) {
    this->postnetCode = postnet;
}

void Zipcode::setZipcode(int zipcode) {
    this->zipcode = zipcode;
}


/// HELPERS

void Zipcode::postRemoveBoundingMarkers(string &postnetCode) {
    postnetCode = postnetCode.substr(1, postnetCode.length() - 2);
}

void Zipcode::postnetDivideToFiveDigitArray(string *newZipArray, string &postnetCode) {
    string temp;
    for (int zipDigit = 0; zipDigit < 5; zipDigit++) {
        temp = "";
        temp.append(postnetCode.substr((zipDigit * 5), (5)));
        newZipArray[zipDigit] = temp;
    }
}

void Zipcode::arrayPostToIntConversion(string *newZipArray) {
    int masterList[5] = {0, 1, 2, 4, 7};
    int tempDigit[5];
    int tempSum;
    // Loop through each element in the temp digit string array
    for (int digit = 0; digit < 5; digit++) {

        for (int elementInTemp = 0; elementInTemp < 5; elementInTemp++) {
            tempDigit[5 - elementInTemp] = zipArray[digit] % 10;
            zipArray[digit] = zipArray[digit] / 10;
        }

        tempSum = 0;
        for (int postnetDigit = 0; postnetDigit < 5; postnetDigit++) {
            tempSum += masterList[postnetDigit] * (tempDigit[postnetDigit]);
        }
        zipArray[digit] = tempSum;
        if (zipArray[digit] == 11) zipArray[digit] = 0;
    }
}

void Zipcode::zipcodeArrayToIntConversion(int *zipArray, int zipcode) {
    string temp = "";
    for (int i = 0; i < 5; i++) {
        temp.append(to_string(zipArray[i]));
    }
}

int Zipcode::convertStringPostnetToIntegerZipcode() {
    postRemoveBoundingMarkers(tempPostnetCode);
    postnetDivideToFiveDigitArray(newZipArray, tempPostnetCode);
    arrayPostToIntConversion(newZipArray);
    zipcodeArrayToIntConversion(zipArray, zipcode);
    return zipcode;
}

string Zipcode::convertIntegerZipcodeToStringPostnet() {
    return std::string();
}

//test