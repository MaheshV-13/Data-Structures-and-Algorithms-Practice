#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
	int arr[SIZE], front, rear;
	
public:
	Queue() : front(-1), rear(-1) {}
	
	void enqueue(int val) {
		if (rear == SIZE - 1) { // check if the queue is full, if rear == the last index(4) then it is full
			cout << "Queue is full\n";
		}
		else {
			if (front == -1){ // if front value is -1, then it will update the front index to 0
				front = 0;
			} 
			arr[++rear] = val;// increment the rear from -1 to 0 and insert the value
		}
	}
	
	void dequeue() {
		if (front == -1 || front > rear) {
			cout << "Queue is empty\n";
		}
		else {
			cout << "Dequeued: " << arr[front++] << endl;
		}
	}
	
	void display() {
		if (front == -1 || front > rear) {
			cout << "Queue is empty\n";
		}
		else {
			cout << "Queue: ";
			for (int i = front; i <= rear; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	Queue q; // create queue of size 5 with f,r value = -1
	q.enqueue(10); // insert value of 10 from rear  (f,r = 0)
	q.enqueue(20); // insert value of 20 from rear  (f = 0, r -> 1)
	q.enqueue(30); // insert value of 30 from rear  (f = 0, r -> 2)
	q.display();
	q.dequeue();
	q.display();
	
	return 0;
	
}
