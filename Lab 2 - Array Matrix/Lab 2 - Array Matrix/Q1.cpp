#include <iostream>
#include <vector>
using namespace std;

int main() {
	

    int n;
    cout << "How many students?: ";
    cin >> n;
    vector<int> marks(n);
    
    cout << "Enter marks: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
    }
	cout << endl;
	
    cout << "Marks entered: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": " << marks[i] << endl;
    }

    return 0;
    
}

