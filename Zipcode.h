#pragma once
#include <iostream>
#include <string>
using namespace std;


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