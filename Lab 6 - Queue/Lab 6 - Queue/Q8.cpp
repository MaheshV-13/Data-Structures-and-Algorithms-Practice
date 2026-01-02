#include <iostream>
#include <string>
using namespace std;

struct Customer {
    string name;
    int age, ticketNo;
    Customer* next;
};

class Queue {
    Customer* front;
    Customer* rear;

public:
    Queue() : front(NULL), rear(NULL) {}

    void enqueue(string name, int age, int tNo) {
        Customer* newCust = new Customer;
        newCust->name = name;
        newCust->age = age;
        newCust->ticketNo = tNo;
        newCust->next = NULL;

        if (!rear)
            front = rear = newCust;
        else {
            rear->next = newCust;
            rear = newCust;
        }
    }

    bool isEmpty() {
        return front == NULL;
    }

    void serve() {
        if (isEmpty()) return;

        Customer* temp = front;
        cout << "Serving: " << temp->name << " (Age: " << temp->age
             << ", Ticket: " << temp->ticketNo << ")\n";

        front = front->next;
        if (!front)
            rear = NULL;
        delete temp;
    }
};

int main() {
    Queue vip, senior, normal;

    vip.enqueue("Alice", 35, 101);
    normal.enqueue("Bob", 25, 102);
    senior.enqueue("Charlie", 68, 103);
    vip.enqueue("Diana", 40, 104);
    normal.enqueue("Evan", 30, 105);

    int i;
    for (i = 0; i < 5; ++i) {
        if (!vip.isEmpty()) vip.serve();
        else if (!senior.isEmpty()) senior.serve();
        else if (!normal.isEmpty()) normal.serve();
    }

    return 0;
}

