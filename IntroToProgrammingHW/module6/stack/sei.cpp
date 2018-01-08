#include <iostream>
#include <vector>

using namespace std;
const TABLE_SIZE =4;

struct CommandStruct {
    char *command;
    char *user;
    int (*commandHandler)(/*params*/);
    
} commandTable[] = {
    { "push ", pushCommand },
    { "peek ", peekCommand },
    { "pop ", popCommand },
    { "end ", endCommand },
};


class Stack {
private:
    vector<int> elements;
public:
    string stringa;
    int integers = 0;

    int peek() {
        int first_ele = 0;
        if (!elements.empty()) {
            first_ele = elements[0];
            cout << endl;
        } else {
            throw runtime_error("error: stack is empty");
        }
        return first_ele;
    }

    int pop() {
        int first_ele = 0;
        if (!elements.empty()) {
            first_ele = elements[0];
            elements.erase(elements.begin());
        } else {
            throw runtime_error("error: stack is empty");
        }
        return first_ele;
    }

    void push(int element) {
        elements.push_back(element);
    }

    void end() {
        if (!elements.empty()) {
            for (int &i: elements) {
                cout << i;
            }
            cout << endl;
        } else {
            throw runtime_error("error: stack is empty");
        }
    }
};

Stack stack1;
bool run_command() {
    char command;
    char user = stack1;
    cin >> command;
    for (int i = 0; i < TABLE_SIZE; ++i) {
    if (command == commandTable[i].command) { 
        commandTable[i].user.commandHandler();
        break;
        }
    }
    if(command =="end"){
        return false;
    }
}

int main() {
    try {
        bool running = true;
        while (running) {
            running = run_command();
        }
    } catch (runtime_error &e) {
        cerr << e.what() << endl;
    }
    return 0;
}