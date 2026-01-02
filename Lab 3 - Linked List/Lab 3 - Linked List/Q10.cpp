#include <iostream>
#include <string>
using namespace std;

struct Patient {
    string name;
    int age;
    Patient* next;
};

void addPatient(Patient*& head, Patient*& tail, string name, int age) {
    Patient* newPatient = new Patient;
    newPatient->name = name;
    newPatient->age = age;
    newPatient->next = NULL;

    if (head == NULL) {
        head = tail = newPatient;
    } else {
        tail->next = newPatient;
        tail = newPatient;
    }
}

void removePatient(Patient*& head) {
    if (head == NULL) {
        cout << "No patients in the waiting list." << endl;
        return;
    }

    Patient* temp = head;
    head = head->next;
    cout << "Patient seen: " << temp->name << ", Age: " << temp->age << endl;
    delete temp;
}

void displayList(Patient* head) {
    if (head == NULL) {
        cout << "Waiting list is empty." << endl;
        return;
    }

    cout << "Current Waiting List: " << endl;
    int index = 1;
    while (head != NULL) {
        cout << index << ". Name: " << head->name << ", Age: " << head->age << endl;
        head = head->next;
        index++;
    }
}

int main() {
    Patient* head = NULL;
    Patient* tail = NULL;

    int choice;

    do {
        cout << "\n--- Hospital Waiting List Menu ---" << endl;
        cout << "1. Add New Patient" << endl;
        cout << "2. Patient Seen (Remove from Front)" << endl;
        cout << "3. Display Waiting List" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int age;
                cout << "Enter patient name: ";
                cin >> ws;
                getline(cin, name);
                cout << "Enter age: ";
                cin >> age;
                addPatient(head, tail, name, age);
                break;
            }
            case 2:
                removePatient(head);
                if (head == NULL) tail = NULL;
                break;

            case 3:
                displayList(head);
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 4);

    while (head != NULL) {
        Patient* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

