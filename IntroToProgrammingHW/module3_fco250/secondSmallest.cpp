#include <iostream>
#include <vector>
#include <exception>

using namespace std;

vector<int> output_vector_of_numbers() {
	vector<int> updatedList;
	int number;
	while (cin >> number) {
		updatedList.push_back(number);
	}
	return updatedList;
}
vector<int> sorting(vector<int> vector) {
	for (int j = 1; j < vector.size(); j++) {
		int key = vector[j];
		int i = j - 1;
		while (i >= 0 && vector[i] > key) {
			vector[i + 1] = vector[i];
			i = i - 1;
		}
		vector[i + 1] = key;
	}
	return vector;
}
int isSecondSmallest(vector<int> vector) {
	const int MIN_POSSIBLE = -2147483647;
	int smallest = vector[0];
	int secondSmallest = MIN_POSSIBLE;
	for (int j = 0; j < vector.size(); j++) {
		if (smallest < vector[j] && j > 0) {
			secondSmallest = vector[j];
			return secondSmallest;
		}
		else if (smallest == secondSmallest) {
			continue;
		}
		else if ((smallest >= secondSmallest && j == vector.size() - 1) || vector.size() == 1) {
			throw runtime_error("error: no second smallest");
		}
	}
}
int main() {
	cout << "Enter the numbers in random order: ";
	vector<int> my_vector = output_vector_of_numbers();
	vector<int> sorted = sorting(my_vector);
	try {
		int secondSmallest = isSecondSmallest(sorted);
		cout << "The second smallest number is " << secondSmallest << endl;
	}
	catch (runtime_error &e) {
		cerr << e.what() << endl;
		return 1;
	}
	return 0;
}