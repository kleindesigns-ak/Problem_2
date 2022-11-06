#include <iostream>
#include "Zipcode.h"

using namespace std;

int main(){
    // Comparison array == {7, 4, 2, 1, 0}
    Zipcode test("1"
                 "10100"
                 "10100"
                 "01100"
                 "00101"
                 "00110"
                 "1");
    cout << endl;
    cout << "Zipcode is " << test.getZipcode() << "." << endl;
    cout << "Postnet Code is " << test.getPostnetCode() << "." << endl;
    return 0;
}