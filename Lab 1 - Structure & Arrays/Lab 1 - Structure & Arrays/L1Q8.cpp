#include <iostream>
#include <vector>

using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

int main() {
	
	vector<Student> students;  // dynamic memory
	int choice;
    
    do {
    	cout << endl;
		cout << "1. Add Student" << endl;
    	cout << "2. Remove Student" << endl;
    	cout << "3. Display All" << endl;
    	cout << "4. Exit" << endl;
    	cout << "Choose: ";
    	cin >> choice;
    	
    	if(choice == 1) {
    		
    		Student s; // temp storage
    		
        	cout << "Enter Roll No: ";
        	cin >> s.rollNo;
        	cout << "Enter Name: ";
        	cin >> s.name;
        	cout << "Enter Marks: ";
        	cin >> s.marks;
        	students.push_back(s); // update students vector
        	cout << endl;
    
		} 
		else if(choice == 2) {
			
			int removeNo;
			cout << "Enter roll number to remove: ";
			cin >> removeNo;
			
			for(int i = 0; i < students.size(); i++) {		
				if(students[i].rollNo == removeNo) {
					students.erase(students.begin() + i); 
					break;
				}
			}	
		}
		else if(choice == 3) {
			
			cout << endl;
			cout << "--- Student List ---" << endl;
			for (int i = 0; i < students.size(); i++) {
				cout << "Roll No: " << students[i].rollNo << ", ";
				cout << "Name: " << students[i].name << ", ";
				cout << "Marks: " << students[i].marks;
				cout << endl;
			}
		}
    		
	} while (choice != 4);
	
	
    return 0;
}
