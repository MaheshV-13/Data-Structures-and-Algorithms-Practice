#include <iostream>
#include <cstdlib>
using namespace std;

// QUESTIONS (1 - 4)
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void createList() {
    int values[5] = {10, 20, 30, 40, 50};
    Node* temp = NULL;
    Node* tail = NULL;

    for (int i = 0; i < 5; i++) {
        Node* newNode = new Node();
        newNode->data = values[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    tail->next = head;
}

void displayList() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* tail = head;
    while (tail->next != head)
        tail = tail->next;

    newNode->next = head;
    tail->next = newNode;
    head = newNode;
}

void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* tail = head;
    while (tail->next != head)
        tail = tail->next;

    tail->next = newNode;
    newNode->next = head;
}

void deleteHead() {
    if (head == NULL)
        return;

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* tail = head;
    while (tail->next != head)
        tail = tail->next;

    Node* temp = head;
    head = head->next;
    tail->next = head;
    delete temp;
}

// ASSIGNMENT QUESTIONS (5 - 7)
void deleteLast() {
    if (head == NULL)
        return;

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* prev = NULL;
    Node* curr = head;

    while (curr->next != head) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = head;
    delete curr;
}

int searchElement(int value) {
    if (head == NULL)
        return -1;

    Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == value)
            return pos;
        temp = temp->next;
        pos++;
    } while (temp != head);

    return -1;
}

struct Process {
    int pid;
    int burst;
    int remaining;
    Process* next;
};

Process* createProcessNode(int pid, int burst) {
    Process* newP = new Process();
    newP->pid = pid;
    newP->burst = burst;
    newP->remaining = burst;
    newP->next = NULL;
    return newP;
}

void simulateRoundRobin() {
    int n;
    const int timeUnit = 2; 
    cout << "\nEnter number of processes: ";
    cin >> n;

    Process* headP = NULL;
    Process* tailP = NULL;

    for (int i = 0; i < n; i++) {
        int bt;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> bt;
        Process* p = createProcessNode(i + 1, bt);
        if (headP == NULL) {
            headP = tailP = p;
        } else {
            tailP->next = p;
            tailP = p;
        }
    }
    tailP->next = headP; 

    Process* curr = headP;
    Process* prev = tailP;

    cout << "\n--- CPU Scheduling ---\n";
    while (curr != NULL) {
        if (curr->remaining > 0) {
            int execTime = (curr->remaining >= timeUnit) ? timeUnit : curr->remaining;
            cout << "Process " << curr->pid << " runs for " << execTime << " units. ";
            curr->remaining -= execTime;

            if (curr->remaining == 0) {
                cout << "Process " << curr->pid << " completed.\n";
                if (curr == prev) {
                    delete curr;
                    break;
                }

                prev->next = curr->next;
                Process* toDelete = curr;
                curr = curr->next;
                delete toDelete;
            } else {
                cout << "Remaining: " << curr->remaining << " units.\n";
                prev = curr;
                curr = curr->next;
            }
        }
    }
}

int main() {
    createList();
    cout << "Initial list: ";
    displayList();

    insertAtBeginning(5);
    cout << "After inserting 5 at beginning: ";
    displayList();

    insertAtEnd(60);
    cout << "After inserting 60 at end: ";
    displayList();

    deleteHead();
    cout << "After deleting head: ";
    displayList();

    deleteLast();
    cout << "After deleting last node: ";
    displayList();

    int val = 30;
    int pos = searchElement(val);
    if (pos != -1)
        cout << val << " found at position " << pos << endl;
    else
        cout << val << " not found\n";

    simulateRoundRobin();

    return 0;
}


