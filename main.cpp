#include <iostream>
#include "Zipcode.h"

using namespace std;

int main(){
    cout << endl;
    // Comparison array == {7, 4, 2, 1, 0}
    Zipcode test("1"
                 "10100"
                 "10100"
                 "01100"
                 "00101"
                 "00110"
                 "1");
    Zipcode test2(99705);

    cout << "Zipcode is        :  " << test.getZipcode() << endl;
    cout << "Postnet Code is   :  " << test.getPostnetCode() << endl << endl;

    cout << "Zipcode 2 is      :  " << test2.getZipcode() << endl;
    cout << "Postnet 2 Code is :  " << test2.getPostnetCode() << endl;

    return 0;
}