#include <iostream>
using namespace std;

int main() {
	
    int mat[3][3] = {{3, 2, 1}, {4, 5, 6}, {1, 1, 1}};
    int maxSum = 0;
	int rowIndex = 0;
	
	cout << "Original Matrix: " << endl;
    for (int i = 0; i < 3; i++) {
        int rowSum = 0;
        for (int j = 0; j < 3; j++) {
        	cout << mat[i][j] << " ";
        	rowSum += mat[i][j];   	
		}
		cout << endl;
        if (rowSum > maxSum) {
            maxSum = rowSum;
            rowIndex = i;
        }
    }

    cout << "Row with max sum: " << rowIndex + 1 << " (Sum = " << maxSum << ")" << endl;
    return 0;
    
}

