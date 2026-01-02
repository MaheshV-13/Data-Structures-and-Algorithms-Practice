#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack {
    string arr[MAX];
    int top;

public:
    Stack() { 
		top = -1; 
	}

    void push(string x) { 
		if (top < MAX - 1) {
			arr[++top] = x;
		}  
	}

    string pop() { 
		return top >= 0 ? arr[top--] : ""; 
	}

    bool isEmpty() { 
		return top == -1; 
	}
};

int main() {
    Stack undo, redo;
    string text = "", input;
    int choice;

    while (true) {
        cout << "\nCurrent Text: " << text;
        cout << "\n1. Type\n2. Undo\n3. Redo\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter text to add: ";
            cin >> input;
            undo.push(text);
            text += input;
            while (!redo.isEmpty()) redo.pop();
        } 
		else if (choice == 2) {
            if (undo.isEmpty()) {
            	cout << "Nothing to undo.\n";
			}
            else {
                redo.push(text);
                text = undo.pop();
            }
        } 
		else if (choice == 3) {
            if (redo.isEmpty()) {
            	cout << "Nothing to redo.\n";
			}
            else {
                undo.push(text);
                text = redo.pop();
            }
        } else if (choice == 4) {
            break;
        }
    }

    return 0;
}

