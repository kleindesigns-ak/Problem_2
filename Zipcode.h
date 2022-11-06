#pragma once
#include <iostream>
#include <string>
using namespace std;

class Zipcode {
public:
    Zipcode();
    explicit Zipcode(int zipcode);          ///TODO : Check 'Explicit' keyword meaning
    explicit Zipcode(string postnetCode);
    string getPostnet();
    int getZipcode();
    void setPostnet(const string& postnet);
    void setZipcode(int zipcode);
    int convertStringPostnetToIntegerZipcode();
    string convertIntegerZipcodeToStringPostnet();
private:
    string tempPostnetCode;
    string postnetCode;
    int zipcode;
    int zipArray[5] = {0, 0, 0, 0, 0};
    string newZipArray[5] = {"", "", "", "", ""};
    void postRemoveBoundingMarkers(string& postnetCode);
    void postnetDivideToFiveDigitArray(string *newZipArray, string& postnetCode);
    void arrayPostToIntConversion(string *newZipArray);
    void zipcodeArrayToIntConversion(int zipArray[], int zipcode);
};