#include <iostream>

using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

void sortDescending(Student students[]) {
    
    for (int i = 0; i < 3 - 1; i++) {
        for (int j = 0; j < 3 - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
                
            }
        }
    }
}

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
    
    sortDescending(students);
    cout << "--- Student sorted by marks (descending) ---" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "Student " << i + 1 << ": " << endl;
        cout << "Roll Number: " << students[i].rollNo << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Marks: " << students[i].marks << endl;
        cout << endl;
    }

    return 0;
}