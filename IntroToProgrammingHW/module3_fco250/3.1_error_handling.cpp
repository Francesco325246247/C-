#include <iostream>

using namespace std;

void ask_for_integer() {
		int integer;
		cout << "Enter an integer" << endl;
		cin >> integer;
		if (cin.fail()) {
			cout <<"Error: Invalid input, ending program"  << endl;
		}
		else {
			cout << integer << " OK" << endl;
			cin.clear();
			ask_for_integer();
		}
	}
int main()
{
    ask_for_integer();
}
