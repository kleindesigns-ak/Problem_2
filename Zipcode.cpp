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

    // Getters
int Zipcode::getZipcode() {
    return zipcode;
}

string Zipcode::getPostnetCode() {
    return convertIntegerZipcodeToStringPostnet(zipcode);
}

    // Setters
void Zipcode::setZipcode(int zipcode) {
    this->zipcode = zipcode;
}

void Zipcode::setPostnetCode(string postnet) {
    this->zipcode = convertStringPostnetToIntegerZipcode(postnet);
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
string Zipcode::convertIntegerZipcodeToStringPostnet(int &zipcode) {
    string postnetCode = "";

    intZipToStringZip(zipcode, postnetCode);
    stringZipToPostnetCode(postnetCode);

    return postnetCode;
}

    void Zipcode::intZipToStringZip(int &zipcode, string &postnetCode) {
        postnetCode = to_string(zipcode);
    }

    void Zipcode::stringZipToPostnetCode(string &postnetCode) {
        // First bounding 1 of postnet code
        string temp = "1";

        // Add integers in converted postnet format one digit at a time
        for (int stringZipDigit = 0; stringZipDigit < 5; stringZipDigit++) {
            //switch int values for postnet equivalents
            switch (stoi(postnetCode.substr(stringZipDigit, 1))) {
                case 1:
                    temp.append("00011");
                    break;
                case 2:
                    temp.append("00101");
                    break;
                case 3:
                    temp.append("00110");
                    break;
                case 4:
                    temp.append("01001");
                    break;
                case 5:
                    temp.append("01010");
                    break;
                case 6:
                    temp.append("01100");
                    break;
                case 7:
                    temp.append("10001");
                    break;
                case 8:
                    temp.append("10010");
                    break;
                case 9:
                    temp.append("10100");
                    break;
                case 0:
                    temp.append("11000");
                    break;
            }

        }
        temp.append("1");
        postnetCode = temp;
    }
