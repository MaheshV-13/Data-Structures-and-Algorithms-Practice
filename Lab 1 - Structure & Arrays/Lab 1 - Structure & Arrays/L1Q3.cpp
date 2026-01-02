#include <iostream>

using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

int main() {

    Student students[3];

    for(int i = 0; i < 3; i++) {
        cout << "Enter details for student " << i + 1 << ": " << endl;
        cout << "Roll Number: ";
        cin >> students[i].rollNo;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Marks: ";
        cin >> students[i].marks;
        cout << endl;
    }

    cout << "--- Student Records ---" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "Student " << i + 1 << ": " << endl;
        cout << "Roll Number: " << students[i].rollNo << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Marks: " << students[i].marks << endl;
        cout << endl;
    }
    
    int searchrollNo;
    cout << "Enter roll number to search: ";
    cin >> searchrollNo;
    
    bool found = false;
    for(int i = 0; i < 3; i++) {
        if (students[i].rollNo == searchrollNo){
            cout << "Student " << i + 1 << ": " << endl;
            cout << "Roll Number: " << students[i].rollNo << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Marks: " << students[i].marks << endl;
            found = true;
            break;
        }
    }
    
    if (!found){
        cout << "Student not found!";
    }

    return 0;
}
