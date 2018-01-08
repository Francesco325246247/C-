#include <iostream>
#include <vector>

using namespace std;

int ask_num_element() {
	int elements;
	cout << "Please enter the number of elements: ";
	cin >> elements;
	if (!std::cin) {
		throw std::runtime_error("invalid input");
	}
	return elements;
}
vector<int> ask_list_to_be_sorted() {
	vector<int> list;
	cout << "Enter the list to be sorted: ";
	int number;
	while (cin >> number) {
		list.push_back(number);
	}
	return list;
}
vector<int> sort_elements(vector<int> to_be_sorted& , const int tot_ele) {
	int temp = 0;
	int end = 0;
	bool sorted = false;
	while (sorted == false) {
		bool swapped = false;
		for (int i = 0; i<tot_ele - 1; i++) {
			if (to_be_sorted[i] > to_be_sorted[i + 1]) {
				temp = to_be_sorted[i];
				to_be_sorted[i] = to_be_sorted[i + 1];
				to_be_sorted[i + 1] = temp;
				swapped = true;
				end++;
			}if (!swapped) {
				sorted = true;
				cout << "Sorted is set to True." << endl;
				break;
			}
		}
	}return to_be_sorted;
}

void print_list(vector<int>sorted_list) {
	int next_element = 0;
	cout << "The sorted list is: ";
	while (next_element < sorted_list.size()) {
		cout << sorted_list[next_element];
		next_element++;
	}cout << endl;
}

int main() {
	
	try {
	    int num_of_elements = ask_num_element();
	    vector<int> list = ask_list_to_be_sorted();
	    vector<int> sorted_list = sort_elements(list, num_of_elements);
	    print_list(sorted_list);
	}
	catch (runtime_error &e) {
		cerr << e.what() << endl;
		return 1;
	}

	return 0;
}