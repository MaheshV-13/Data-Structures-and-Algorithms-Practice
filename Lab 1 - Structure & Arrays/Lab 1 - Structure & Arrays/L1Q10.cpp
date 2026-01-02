#include <iostream>

using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

struct StudentArray {
    int rollNo[3];
    string name[3];
    float marks[3];
};

int main() {
	
	Student students[3] = {
		{1, "Asha", 90},
		{2, "Kaja", 85},
		{3, "Niro", 88}
	};
	
	cout << "Array of Structures: " << endl;
	for(int i = 0; i < 3; i++) {
		cout << students[i].rollNo << " " << students[i].name << " " << students[i].marks << endl;
	}
	
	StudentArray studentsArray = {
		{10, 11, 12},
		{"Vidhu", "Eshan", "Fariha"},
		{78.5, 80, 69.2}
	};
	
	cout << endl;
	cout << "Structure of Arrays: " << endl;
	for(int i = 0; i < 3; i++) {
		cout << studentsArray.rollNo[i] << " " << studentsArray.name[i] << " " << studentsArray.marks[i] << endl;
	}
    return 0;
}
