#include <iostream>
#include "Zipcode.h"

using namespace std;

int main(){
    cout << endl;

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TEST 1 ~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Test constructor with string input
    Zipcode test("1"
                 "10100"
                 "10100"
                 "01100"
                 "00101"
                 "00110"
                 "1");

    // Test constructor with string input for both formats of output
    cout << "Zipcode is        :  " << test.getZipcode() << endl;
    cout << "Postnet Code is   :  " << test.getPostnetCode() << endl << endl;


    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TEST 2 ~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Test constructor with integer input
    Zipcode test2(99705);

    // Test constructor with integer input for both formats of output
    cout << "Zipcode 2 is      :  " << test2.getZipcode() << endl;
    cout << "Postnet 2 Code is :  " << test2.getPostnetCode() << endl << endl;


    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TEST 3 ~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Test constructor with no input and manually set string postnet
    Zipcode test3;
    test3.setPostnetCode("1"
                         "10001"
                         "11000"
                         "01100"
                         "00110"
                         "00011"
                         "1");

    // Test constructor with integer input for both formats of output
    cout << "Zipcode 3 is      :  " << test3.getZipcode() << endl;
    cout << "Postnet 3 Code is :  " << test3.getPostnetCode() << endl << endl;


    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TEST 4 ~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Test constructor with no input and manually set integer zipcode
    Zipcode test4;
    test4.setZipcode(99702);

    // Test constructor with integer input for both formats of output
    cout << "Zipcode 4 is      :  " << test4.getZipcode() << endl;
    cout << "Postnet 4 Code is :  " << test4.getPostnetCode() << endl << endl;

    return 0;
}