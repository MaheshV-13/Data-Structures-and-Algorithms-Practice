#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void displayForward(Node* head) {
    cout << "Doubly Linked List (forward): ";
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void searchAndTrace(Node* head, int key) {
    Node* current = head;
    int position = 1;
    bool found = false;

    while (current != NULL) {
        if (current->data == key) {
            cout << "Found at position " << position << " (forward)" << endl;

            cout << "Backward from found node: ";
            Node* temp = current;
            while (temp != NULL) {
                cout << temp->data;
                temp = temp->prev;
                if (temp != NULL) cout << " <- ";
            }
            cout << " <- NULL" << endl;

            found = true;
            break;
        }
        current = current->next;
        position++;
    }

    if (!found) {
        cout << "Value " << key << " not found in the list." << endl;
    }
}

int main() {
    int N;
    cout << "Enter no. elements (n): ";
    cin >> N;

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 1; i <= N; i++) {
        int value;
        cout << "Node #" << i << ": ";
        cin >> value;

        Node* newNode = createNode(value);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    displayForward(head);

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    searchAndTrace(head, key);

    return 0;
}

