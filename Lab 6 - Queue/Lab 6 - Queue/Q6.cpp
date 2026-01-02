#include <iostream>
using namespace std;

#define MAX 100

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

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }

    int size() {
        if (front == -1 || front > rear) return 0;
        return rear - front + 1;
    }

    bool isEmpty() {
        return size() == 0;
    }
};

int main() {
    Queue q, firstHalf, secondHalf;
    int vals[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(vals) / sizeof(vals[0]);
    int i;

    for (i = 0; i < n; ++i)
        q.enqueue(vals[i]);

    cout << "Original Queue: ";
    q.display();

    int half = q.size() / 2;

    for (i = 0; i < half; ++i)
        firstHalf.enqueue(q.dequeue());

    while (!q.isEmpty())
        secondHalf.enqueue(q.dequeue());

    cout << "First Half: ";
    firstHalf.display();

    cout << "Second Half: ";
    secondHalf.display();

    while (!firstHalf.isEmpty() || !secondHalf.isEmpty()) {
        if (!firstHalf.isEmpty()) q.enqueue(firstHalf.dequeue());
        if (!secondHalf.isEmpty()) q.enqueue(secondHalf.dequeue());
    }

    cout << "Interleaved Queue: ";
    q.display();

    return 0;
}

