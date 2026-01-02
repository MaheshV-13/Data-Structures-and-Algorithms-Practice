#include <iostream>
using namespace std;

int main() {
	
    int array[] = {10, 9, 8 , 6, 4, 1, 2, 3, 7, 5, 25};
    int size = sizeof(array) / sizeof(array[0]);
    int max = array[0];
	int min = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
        	max = array[i];
		}
        if (array[i] < min) {
        	min = array[i];
		}
    }

    cout << "Maximum: " << max << endl;
	cout << "Minimum: " << min << endl;
    return 0;
}

