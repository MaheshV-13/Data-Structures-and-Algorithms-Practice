#include <iostream>
#include <fstream>

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
        cout << "Roll No: ";
        cin >> students[i].rollNo;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Marks: ";
        cin >> students[i].marks;
        cout << endl;
    }
    
    ofstream outFile("students.txt");
    if(!outFile){
    	cerr << "Error opening file for writing." << endl;
    	return 1;
	}
    
    for(int i = 0; i < 3; i++){
    	outFile << students[i].rollNo << endl;
    	outFile << students[i].name << endl;
    	outFile << students[i].marks << endl;
	}
	
	outFile.close();
	
	ifstream inFile("students.txt");
	if(!inFile){
    	cerr << "Error opening file for reading." << endl;
    	return 1;
	}
	
	cout << "--- Student Records from students.txt ---" << endl;
	for(int i = 0; i < 3; i++){
		inFile >> students[i].rollNo;
		inFile >> students[i].name;
		inFile >> students[i].marks;
		
		cout << "Roll No: " << students[i].rollNo << ", ";
        cout << "Name: " << students[i].name << ", ";
        cout << "Marks: " << students[i].marks;
        cout << endl;
		
	}
	
    return 0;
}
