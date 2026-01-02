#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class LinkedQueue {
	Node *front, *rear; // points to first and last node

public: 
	LinkedQueue() : front(NULL), rear(NULL) {} // assign the pointer of front and rear to NULL
	
	void enqueue(int val) {
		Node* newNode = new Node{val, NULL}; // create new node with NULL pointer
		if (!rear) { // if rear pointer is NULL, linked list is empty
			front = rear = newNode; // front and rear points to/becomes new node
		}
		else {
			rear -> next = newNode; // the next of rear will be pointing to the new node
			rear = newNode; // new node becomes the rear
		}
	}
	
	void dequeue() {
		if (!front) { // if front pointer is NULL, linked list is empty
			cout << "Queue is empty\n";
		}
		else {
			Node* temp = front; // create a new node called temp and point it to the node front is pointing to
			cout << "Dequeued: " << temp -> data << endl; 
			front = front -> next;
			if (!front) {
				rear = NULL;
			}
			delete temp;
		}
	}
	
	void display() {
		if (!front) { // if front pointer is NULL, linked list(queue) is empty
			cout << "Queue is empty\n";
		}
		else {
			Node* temp = front; // create a new node called temp and point it to the node front is pointing to
			cout << "Queue: ";
			while(temp) { // conti
				cout << temp -> data << " ";
				temp = temp -> next;
			}
			cout << endl;
		}
	}
};

int main() {
	LinkedQueue q; // create and declaring the linked list (front, rear = NULL)
	q.enqueue(5);
	q.enqueue(15);
	q.enqueue(25);
	q.display();
	q.dequeue();
	q.display();
	
}
