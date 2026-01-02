#include <iostream>
using namespace std;

struct Node {
    int data, priority;
    Node* next;
};

class PriorityQueue {
    Node* front;

public:
    PriorityQueue() : front(NULL) {}

    void enqueue(int val, int pri) {
        Node* newNode = new Node{val, pri, NULL};
        if (!front || pri < front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* temp = front;
            while (temp->next && temp->next->priority <= pri)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void dequeue() {
        if (!front) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Dequeued: " << front->data << " (Priority: " << front->priority << ")\n";
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    void display() {
        Node* temp = front;
        cout << "Queue: ";
        while (temp) {
            cout << "[" << temp->data << " Priority:" << temp->priority << "] ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue(10, 2);
    pq.enqueue(20, 1);
    pq.enqueue(30, 3);
    pq.display();
    pq.dequeue();
    pq.display();
    return 0;
}

