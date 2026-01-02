#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void displayList(Node* head) {
    Node* current = head;
    cout << "Linked List Contents: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Question 1: Create a singly linked list of 5 nodes
Node* createInitialList() {
    Node* head = NULL;
    Node* tail = NULL;
    cout << "Question 1: Create a singly linked list of 5 nodes\n";
    for (int i = 1; i <= 5; i++) {
        int value;
        cout << "Node #" << i << ": ";
        cin >> value;

        Node* newNode = createNode(value);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Question 2: Insert a node at the beginning
Node* insertAtBeginning(Node* head, int value) {
    cout << "\nQuestion 2: Insert at beginning\n";
    Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

// Question 3: Insert a node at the end
Node* insertAtEnd(Node* head, int value) {
    cout << "\nQuestion 3: Insert at end\n";
    Node* newNode = createNode(value);
    if (head == NULL) return newNode;

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Question 4: Delete node from beginning
Node* deleteFromBeginning(Node* head) {
    cout << "\nQuestion 4: Delete from beginning\n";
    if (head == NULL) {
        cout << "List is empty.\n";
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Question 5: Delete node from end
Node* deleteFromEnd(Node* head) {
    cout << "\nQuestion 5: Delete from end\n";
    if (head == NULL) {
        cout << "List is empty.\n";
        return NULL;
    }
    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    delete current->next;
    current->next = NULL;
    return head;
}

// Question 6: Insert node at a specific position (1-based)
Node* insertAtPosition(Node* head, int value, int position) {
    cout << "\nQuestion 6: Insert at position " << position << endl;
    if (position < 1) {
        cout << "Invalid position. Must be 1 or greater.\n";
        return head;
    }

    Node* newNode = createNode(value);
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    int count = 1;
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        cout << "Invalid position. List is shorter than " << position << " nodes.\n";
        delete newNode;
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Question 7: Delete the first node with a specific value
Node* deleteByValue(Node* head, int key) {
    cout << "\nQuestion 7: Delete node with value " << key << endl;
    if (head == NULL) {
        cout << "List is empty.\n";
        return NULL;
    }

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        cout << "Deleted node with value: " << key << endl;
        delete temp;
        return head;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data != key) {
        current = current->next;
    }

    if (current->next == NULL) {
        cout << "Value " << key << " not found.\n";
        return head;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    cout << "Deleted node with value: " << key << endl;
    delete temp;
    return head;
}

// Question 8: Search for a value and print positions
void searchValue(Node* head, int key) {
    cout << "\nQuestion 8: Search for value " << key << endl;
    int position = 1;
    bool found = false;

    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            cout << "Value found at position: " << position << endl;
            found = true;
        }
        current = current->next;
        position++;
    }

    if (!found) {
        cout << "Value not found in the list.\n";
    }
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    Node* head = NULL;

    // Q1
    head = createInitialList();
    displayList(head);

    // Q2
    int valBegin;
    cout << "\nEnter value to insert at beginning: ";
    cin >> valBegin;
    head = insertAtBeginning(head, valBegin);
    displayList(head);

    // Q3
    int valEnd;
    cout << "\nEnter value to insert at end: ";
    cin >> valEnd;
    head = insertAtEnd(head, valEnd);
    displayList(head);

    // Q4
    head = deleteFromBeginning(head);
    displayList(head);

    // Q5
    head = deleteFromEnd(head);
    displayList(head);

    // Q6
    int posVal, pos;
    cout << "\nEnter value to insert: ";
    cin >> posVal;
    cout << "Enter position to insert (1-based): ";
    cin >> pos;
    head = insertAtPosition(head, posVal, pos);
    displayList(head);

    // Q7
    int delVal;
    cout << "\nEnter value to delete: ";
    cin >> delVal;
    head = deleteByValue(head, delVal);
    displayList(head);

    // Q8
    int searchVal;
    cout << "\nEnter value to search for: ";
    cin >> searchVal;
    searchValue(head, searchVal);

    freeList(head);
    return 0;
}

