#include "Zipcode.h"

Zipcode::Zipcode() {
    this->zipcode = 0;    /*
                            "1"         // Bounding 1
                            "11000"     // Equivalent to 0 as an int
                            "11000"     // Equivalent to 0 as an int
                            "11000"     // Equivalent to 0 as an int
                            "11000"     // Equivalent to 0 as an int
                            "11000"     // Equivalent to 0 as an int
                            "1"         // Bounding 1
                          */
}

Zipcode::Zipcode(int zipcode) {
    this->zipcode = zipcode;
}

Zipcode::Zipcode(string postnetCode) {
    this->zipcode = convertStringPostnetToIntegerZipcode(postnetCode);
}

/// ~~~~~~~~~~~~~~~~ GETTER AND SETTER FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~

int Zipcode::getZipcode() {
    return zipcode;
}

string Zipcode::getPostnetCode() {
    return string();
}

/// ~~~~~~~~~~~~~~~~~~~~~ HELPER FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Postnet to Zipcode Conversion Functions
int Zipcode::convertStringPostnetToIntegerZipcode(string &postnetCode) {
    string postnetSubdividedIntoFiveArray[5];
    removeFramingOnes(postnetCode);
    dividePostnetStringIntoFive(postnetCode, postnetSubdividedIntoFiveArray);
    convertStringArrayToIntZip(zipcode, postnetSubdividedIntoFiveArray);
    return zipcode;
}

void Zipcode::removeFramingOnes(string &postnetCode) {
    postnetCode = postnetCode.substr(1, (postnetCode.length() - 2) );
}

void Zipcode::dividePostnetStringIntoFive(string &postnetCode, string *fiveElementArray) {
    for (int arrayElement = 0; arrayElement < 5; arrayElement++) {
        fiveElementArray[arrayElement] = postnetCode.substr( (arrayElement * 5) , 5 );
    }
}

void Zipcode::convertStringArrayToIntZip(int &zipcode, string *fiveElementArray) {
    int tempZipArrayInt[5];
    int masterPostnetConversion[5] = {7, 4, 2, 1, 0};
    string zipEquivalentAsString = "";

    for (int zipDigit = 0; zipDigit < 5; zipDigit++) {
        for (int tempElement = 0; tempElement < 5; tempElement++) {
            tempZipArrayInt[tempElement] = 0;
        }
        for (int postDigit = 0; postDigit < 5; postDigit++) {
            //Examine digits of postnet code as substrings and compare them to '1'.
            // If the value is 1, take the corresponding int value from the
            // reference list and add it to the running total for that digit of the int zip code
            if (stoi(fiveElementArray[zipDigit].substr(postDigit, 1)) == 1)
                tempZipArrayInt[zipDigit] += masterPostnetConversion[postDigit];
            if (tempZipArrayInt[zipDigit] == 11)
                tempZipArrayInt[zipDigit] = 0;
        }
        zipEquivalentAsString.append(to_string(tempZipArrayInt[zipDigit]));
    }
    zipcode = stoi(zipEquivalentAsString);
}

// Zipcode to Postnet Conversion Functions





/*
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

 */