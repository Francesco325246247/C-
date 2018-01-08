#include <iostream>
#include <stdlib.h>

using namespace std;

void ask_for_integer() {
    int integer;
    cout << "Enter an integer" << endl;
    cin >> integer;
        if (cin.fail()) {
            throw integer;
        } else {
            cout << integer << " OK" << endl;
        }
    ask_for_integer();
}

int main()
{
    try {
        ask_for_integer();
    }catch() {
        cout << "error: input mismatch" << endl;
        exit(0);
        
    }
    return 0;
}
