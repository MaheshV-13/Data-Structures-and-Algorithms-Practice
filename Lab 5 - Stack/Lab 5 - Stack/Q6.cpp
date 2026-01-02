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
    Stack back, forward;
    string current = "home", url;
    int choice;

    while (true) {
        cout << "\nCurrent Page: " << current;
        cout << "\n1. Visit\n2. Back\n3. Forward\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter URL: ";
            cin >> url;
            back.push(current);
            current = url;
            while (!forward.isEmpty()) {
            	forward.pop();
			}
        } 
		else if (choice == 2) {
            if (back.isEmpty()) {
            	cout << "No back history!\n";
			}
            else {
                forward.push(current);
                current = back.pop();
            }
        } 
		else if (choice == 3) {
            if (forward.isEmpty()) {
            	cout << "No forward history!\n";
			}
            else {
                back.push(current);
                current = forward.pop();
            }
        } 
		else if (choice == 4) {
            break;
        }
    }

    return 0;
}

