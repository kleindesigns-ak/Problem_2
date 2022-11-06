#include <iostream>
#include "Zipcode.h"

using namespace std;

int main(){
    // Comparison array == {7, 4, 2, 1, 0}
    Zipcode test("1"
                 "10100"
                 "10010"
                 "10000"
                 "01100"
                 "01010"
                 "1");
    cout << endl;
    cout << test.getPostnet() << endl << endl;
    cout << test.getZipcode() << endl << endl;
    return 0;
}

//test
