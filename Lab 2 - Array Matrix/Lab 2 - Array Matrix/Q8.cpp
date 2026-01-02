#include <iostream>
using namespace std;

int main() {
	
    const int SIZE = 8;
    int grid[SIZE][SIZE] = {
        {5, 3, 8, 6, 7, 2, 1, 4},
        {6, 7, 2, 1, 8, 5, 3, 4},
        {1, 8, 4, 3, 5, 6, 2, 7},
        {2, 5, 3, 3, 4, 1, 6, 8},
        {4, 2, 7, 8, 6, 1, 5, 3},
        {8, 6, 1, 5, 3, 7, 4, 2},
        {3, 4, 5, 2, 1, 8, 7, 6},
        {7, 1, 6, 4, 2, 3, 8, 5}
    };

    cout << "Sudoku Grid (8x8): " << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    bool hasError = false;

    for (int i = 0; i < SIZE; i++) {
        int count[9] = {0};
        for (int j = 0; j < SIZE; j++) {
            int val = grid[i][j];
            if (val < 1 || val > 8) {
            	continue;
			} 
            count[val]++;
            if (count[val] > 1) {
                cout << "Duplicate number in row " << i + 1 << ": " << val << endl;
                hasError = true;
                break;
            }
        }
    }

    for (int j = 0; j < SIZE; j++) {
        int count[9] = {0};
        for (int i = 0; i < SIZE; i++) {
            int val = grid[i][j];
            if (val < 1 || val > 8) {
            	continue;
			} 
            count[val]++;
            if (count[val] > 1) {
                cout << "Duplicate number in column " << j + 1 << ": " << val << endl;
                hasError = true;
                break;
            }
        }
    }

    if (hasError) {
    	cout << endl;
        cout << "Sudoku grid has one or more errors (see above). ";
    }
    
    return 0;
}

