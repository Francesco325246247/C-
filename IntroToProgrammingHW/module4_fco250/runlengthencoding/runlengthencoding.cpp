#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Elements {
	int numero;
	char stringa;
};

string insert_list() {
	string list;
	cout << "Enter the data to be compressed: ";
	getline(cin, list);
	if (cin.fail()) {
		throw runtime_error("error: letter expected");
	}
	return list;
}

vector<Elements> find_the_repetitions(string string2) {

	char previousChar = '1';
	Elements element;
	vector<Elements> list;
	int i = -1;

	for (char& c : string2)
	{
		if (previousChar != c) {
			element.stringa = c;
			element.numero = 0;
			list.push_back(element);
			previousChar = c;
			i++;
		}
		if (previousChar == c) {
			list[i].numero = list[i].numero + 1;
		}
	}
	return list;
}

void printArray(vector<Elements> list) {
    cout << "The compressed data is: ";
	for (std::vector<int>::size_type i = 0; i != list.size(); i++) {
		cout << list[i].numero;
		cout << list[i].stringa;
	}
	cout << endl;
}

int main() {

	try {
		string list = insert_list();
		vector<Elements> vector_mixed = find_the_repetitions(list);
		printArray(vector_mixed);
	}
	catch (runtime_error &e) {
		cerr << e.what() << endl;
		return 1;
	}
	return 0;
}