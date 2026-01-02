#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(char x) {
        if (top < MAX - 1) {
        	arr[++top] = x;
		}
            
    }

    char pop() {
        if (top >= 0)
            return arr[top--];
        return '\0';
    }

    char peek() {
        if (top >= 0)
            return arr[top];
        return '\0';
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(char expr[]) {
    Stack s;
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
        	s.push(ch);
		}    
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty() || !isMatching(s.pop(), ch)) {
            	return false;
			}       
        }
    }
    return s.isEmpty();
}

int main() {
    char expr[MAX];
    cout << "Enter expression: ";
    cin >> expr;

    if (isBalanced(expr)) {
    	cout << "Balanced\n";
	}   
    else {
    	cout << "Not Balanced\n";
	}
        
    return 0;
}

