#include "iostream"
#include "string"

using namespace std;

void check_vu_id(string vu_id) {
	int position = 0;
	for (char& c : vu_id) {
		if (c == 32) {
			continue;
		}
		else if (position <= 2 && ((c <65 || c >90) && (c < 97 || c > 'Z'))) {
			throw runtime_error("error: letter expected");
			break;
		}
		else if (position >2 && (c < '0' || c >57)) {
			throw runtime_error("error: number expected");
			break;
		}
		else if(position ==6 ) {
			cout << "The VUnet ID " << vu_id << " is correct." << endl;
			break;
		}
		position++;
	}
}
void ask_vu_id() {
	string vu_id;
	cout << "Please enter the VUnet ID:";
	getline(cin, vu_id);
	check_vu_id(vu_id);
}
int main()
{
	try {
		ask_vu_id();
	}
	catch (runtime_error &e) {
		cerr << e.what() << endl;
		return 1;
	}
	return 0;
}

