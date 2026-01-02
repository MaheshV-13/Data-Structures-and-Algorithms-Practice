#include <iostream>

using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

void addMarks (Student &students) {
	students.marks += 5;
}


int main() {
    
    int count;
    cout << "Enter number of students: ";
    cin >> count;
    
    Student students[count];
    
    for(int i=0; i < count; i++) {
        cout << "Enter details for student " << i + 1 << ": " << endl;
        cout << "Roll Number: ";
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
        addMarks(students[i]);
        cout << "Marks: " << students[i].marks;
        cout << endl;
    }

    return 0;
}
