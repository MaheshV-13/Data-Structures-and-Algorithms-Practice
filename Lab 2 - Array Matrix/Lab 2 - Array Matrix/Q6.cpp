#include <iostream>
using namespace std;

int main() {
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int transpose[3][2];
	
	cout << "Original Matrix: " << endl;
    for (int i = 0; i < 2; i++) {
    	for (int j = 0; j < 3; j++) {
    		cout << matrix[i][j] << " ";
    		transpose[j][i] = matrix[i][j];
		}
        cout << endl;
	}
        
    cout << endl;
    cout << "Transpose Matrix: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
        	cout << transpose[i][j] << " ";
		}    
        cout << endl;
    }

    return 0;
}

