#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void calc_rectangle(int height, int lenght) {

	double area;
	double diagonal;
	double perimeter;

	area = height * lenght;
	perimeter = 2* (height + lenght);
	diagonal = sqrt(pow(height, 2) + pow(lenght, 2));

	cout << "The perimeter is " << perimeter << ", the area is " << area <<" , the diagonal is " << diagonal <<". " << endl;

	
}

int main() {

	int height;
	int lenght;

	cout << "Please enter the length and width of a rectangle :" << endl;
	cin >> height >> lenght;
	calc_rectangle(height, lenght);

	return 0;
}