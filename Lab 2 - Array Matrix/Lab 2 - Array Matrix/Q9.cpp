#include <iostream>
using namespace std;

int main() {
    const int SIZE = 3;
    int image[SIZE][SIZE] = {
        {230, 100, 50},
        {200, 180, 90},
        {60, 30, 250}
    };

    int brightened[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int increased = image[i][j] + 20;
            brightened[i][j] = (increased > 255) ? 255 : increased;
        }
    }

    cout << "Original Image Matrix: " << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nBrightness-Increased Image Matrix: " << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << brightened[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

