#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(int x) {
        if (top < MAX - 1) {
        	arr[++top] = x;
		}   
    }

    int pop() {
        if (top >= 0)
            return arr[top--];
        return -1;
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    int n, i, x;
    int arr[MAX];
    Stack s;

    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
        s.push(arr[i]);
    }

    cout << "Reversed Array:\n";
    for (i = 0; i < n; i++) {
        arr[i] = s.pop();
        cout << arr[i] << " ";
    }

    return 0;
}

