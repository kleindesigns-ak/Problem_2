#pragma once
#include <iostream>
#include <string>
using namespace std;

/*
class Zipcode {
public:
    string getPostnet();
    int getZipcode();
    void setPostnet(const string& postnet);
    void setZipcode(int zipcode);
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
 */


class Zipcode{
public:
    Zipcode();
    explicit Zipcode(int zipcode);
    explicit Zipcode(string postnetCode);
    int zipcode;
    int getZipcode();
    string getPostnetCode();
private:
    int convertStringPostnetToIntegerZipcode(string &postnetCode);
    static void removeFramingOnes(string &postnetCode);
    static void dividePostnetStringIntoFive(string &postnetCode, string *fiveElementArray);
    static void convertStringArrayToIntZip(int &zipcode, string *fiveElementArray);
};