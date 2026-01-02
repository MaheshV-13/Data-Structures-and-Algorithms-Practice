#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int sales[3][4] = {
        {100, 120, 130, 90},
        {80, 95, 100, 110},
        {60, 70, 75, 65}
    };

    cout << setw(6) << " " << "R1" << setw(6) << "R2" << setw(6) << "R3" << setw(6) << "R4" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "P" << i + 1 << " ";
        for (int j = 0; j < 4; j++) {
            cout << setw(6) << sales[i][j];
        }
        cout << endl;
    }

    return 0;
}

