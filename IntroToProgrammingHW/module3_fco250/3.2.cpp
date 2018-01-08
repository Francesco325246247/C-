#include <iostream>
#include <stdlib.h>

using namespace std;

int ask_for_integer() {
    int integer;
    int a, b;
    cout << "Enter an integer" << endl;
    cin >> integer;
        if (cin.fail()) {
            throw runtime_error("input mismatch");
        } else {
            cout << integer << " OK" << endl;
        }
    ask_for_integer();
}

int main() {
 ask_for_integer();
    return 0;
}
