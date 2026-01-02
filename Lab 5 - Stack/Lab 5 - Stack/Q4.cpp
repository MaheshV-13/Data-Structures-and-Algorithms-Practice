#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
    
public:
    Stack() { 
		top = -1; 
	}

    void push(char x) { 
		arr[++top] = x; 
	}

    char pop() { 
		return arr[top--]; 
	}

    char peek() { 
		return arr[top]; 
	}

    bool isEmpty() { 
		return top == -1; 
	}
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char* expr) {
    Stack s;
    int i = 0;
    while (expr[i] != '\0') {
        char ch = expr[i];

        if (ch == ' ') {
            i++;
            continue;
        }

        if (isalnum(ch)) {
            cout << ch;
            while (isalnum(expr[i + 1])) {
                i++;
                cout << expr[i];
            }
            cout << " ";
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(')
                cout << s.pop() << " ";
            if (!s.isEmpty()) s.pop();
        }
        else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch))
                cout << s.pop() << " ";
            s.push(ch);
        }

        i++;
    }

    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }
}

int main() {
    char expr[MAX];
    cout << "Enter infix expression: ";
    cin.getline(expr, MAX);
    cout << "Postfix: ";
    infixToPostfix(expr);
    return 0;
}

