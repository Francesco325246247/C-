#include "iostream"
#include "math.h"

using namespace std;

void print_quadratic_result(double first_result, double second_result) {
	if (second_result == 0) {
		cout << "There is only one solution." << endl;
		cout << "The solutions is: " << first_result << endl;
	}
	else {
		cout << "There are two solutions." << endl;
		cout << "The solutions are: " << first_result << ", and" << second_result << endl;
	}
}

double calculate_Quadratic(int a, int b, int c) {
	try {
		double x_plus;
		double x_minus;
		double discriminant = sqrt((pow(b, 2) - (4 * a *c)));

		x_plus = (-b + discriminant) / (2 * a);
		x_minus = (-b - discriminant) / (2 * a);

		if (a == 0) {
			throw discriminant;
		}
		else if(discriminant == 0){
			print_quadratic_result( x_plus, 0);
		}
		else {
			print_quadratic_result(x_plus, x_minus);
		}
	}
	catch (int) {
		cout << "error: division by 0" << endl;
		exit(0);
	}
}

void initialize_it() {
	int element_a, element_b, element_c;
	cout << "Please enter the values of a, b, and c respectively: " << endl;
	cin >> element_a >> element_b >> element_c;
	calculate_Quadratic(element_a, element_b, element_c);
}

int main()
{
	initialize_it();
	return 0;
}