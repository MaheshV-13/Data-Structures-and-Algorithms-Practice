#include <iostream>

using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

int main() {

    Student students[3];

    for(int i=0; i < 3; i++) {
        cout << "Enter details for student " << i + 1 << ": " << endl;
        cout << "Roll Number: ";
        cin >> students[i].rollNo;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Marks: ";
        cin >> students[i].marks;
        cout << endl;
    }
    
    
    float total = 0.0;
    float avg;
    cout << "--- Student Records ---" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "Student " << i + 1 << ": " << endl;
        cout << "Roll Number: " << students[i].rollNo << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Marks: " << students[i].marks << endl;
        cout << endl;
        total = total + students[i].marks;
    }
    
    avg = total/3.0;
    cout << "Average Marks of the class: " << avg;

    return 0;
}