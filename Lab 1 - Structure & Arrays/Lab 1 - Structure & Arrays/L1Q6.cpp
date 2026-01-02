#include <iostream>

using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

int main() {
    
    int count;
    cout << "Enter number of students: ";
    cin >> count;
    
    Student* students = new Student[count];
    
    for(int i = 0; i < count; i++) {
        cout << "Enter details for student " << i + 1 << ": " << endl;
        cout << "Roll No: ";
        cin >> students[i].rollNo;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Marks: ";
        cin >> students[i].marks;
        cout << endl;
    }
    
    cout << "--- Student Details ---" << endl;
    for(int i = 0; i < count; i++) {
        cout << "Roll No: " << students[i].rollNo << ", ";
        cout << "Name: " << students[i].name << ", ";
        cout << "Marks: " << students[i].marks << endl;
    }
    
    delete[] students;
    
    return 0;
}

