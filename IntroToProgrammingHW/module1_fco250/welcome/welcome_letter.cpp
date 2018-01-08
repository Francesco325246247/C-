#include <iostream>
#include <string>

using namespace std;

void print_letter(string name, string surname, int age, float height) {

	printf("\n");
	cout << "Hello, " << name << endl;
	printf("\n");
	cout << "Welcome to Computer Programming. You entered the following information:" << endl;
	cout << "Full name: " << name <<" "<< surname << endl;
	cout << "Age: " << age << endl;
	cout << "Height:  " << height << endl;
	printf("\n");
	cout << "We hope you will enjoy the course!" << endl;
	printf("\n");
}

int main() {

	string name;
	string surname;
	int age;
	float height;

	cout << "Please fulfill the following information:" << endl;
	cout << "What's your name?" << endl;
	cin >> name; 
	cout << "What's your surname?" << endl;
	cin >> surname;
	cout << "How old are you?" << endl;
	cin >> age;
	cout << "How tall are you?" << endl;
	cin >> height;

	print_letter(name, surname, age, height);
	


	return 0;
}
