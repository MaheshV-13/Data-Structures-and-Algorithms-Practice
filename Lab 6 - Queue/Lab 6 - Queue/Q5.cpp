#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX], top;
public:
    Stack() { top = -1; }
    void push(int x) { arr[++top] = x; }
    int pop() { return arr[top--]; }
    bool isEmpty() { return top == -1; }
};

class Queue {
    int arr[MAX], front, rear;
public:
    Queue() { front = rear = -1; }

    void enqueue(int x) {
        if (rear == MAX - 1) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if (front == -1 || front > rear) return -1;
        return arr[front++];
    }

    bool isEmpty() { return front == -1 || front > rear; }

    void display() {
        for (int i = front; i <= rear; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    Stack s;    
    int vals[] = {10, 20, 30, 40, 50};
    int n = sizeof(vals) / sizeof(vals[0]);
    
    for (int i = 0; i < n; ++i) {
    	q.enqueue(vals[i]);
	}
        

    cout << "Original Queue: ";
    q.display();

    while (!q.isEmpty()) s.push(q.dequeue());
    while (!s.isEmpty()) q.enqueue(s.pop());

    cout << "Reversed Queue: ";
    q.display();
    return 0;
}

