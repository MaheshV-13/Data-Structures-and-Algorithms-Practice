#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { 
		top = -1; 
	}

    void push(int x) { 
		arr[++top] = x; 
	}

    int pop() { 
		return arr[top--];
	}

    bool isEmpty() { 
		return top == -1; 
	}
};

int evaluatePostfix(char* expr) {
    Stack s;
    int i = 0;

    while (expr[i] != '\0') {
        if (expr[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit(expr[i])) {
            int num = 0;
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            s.push(num);
        }
        else {
            int val2 = s.pop();
            int val1 = s.pop();

            switch (expr[i]) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
            i++;
        }
    }
    return s.pop();
}

int main() {
    char expr[MAX];
    cout << "Enter postfix expression: ";
    cin.getline(expr, MAX);
    cout << "Result: " << evaluatePostfix(expr);
    return 0;
}

