#pragma once
#include <iostream>
#include <string>
using namespace std;


class Zipcode{
public:
        // Constructors
    Zipcode();
    explicit Zipcode(int zipcode);
    explicit Zipcode(string postnetCode);
        // Getters / Setters
    int getZipcode();
    string getPostnetCode();
private:
        // Private Vars
    int zipcode;
        // Main Conversion Functions
    int convertStringPostnetToIntegerZipcode(string &postnetCode);
    string convertIntegerZipcodeToStringPostnet(int &zipcode);
        // Private Int to String Helper Functions
    static void removeFramingOnes(string &postnetCode);
    static void dividePostnetStringIntoFive(string &postnetCode, string *fiveElementArray);
    static void convertStringArrayToIntZip(int &zipcode, string *fiveElementArray);
        // Private Int to String Helper Functions
    static void intZipToStringZip(int &zipcode, string &postnetCode);
    static void stringZipToPostnetCode(string &postnetCode);
};