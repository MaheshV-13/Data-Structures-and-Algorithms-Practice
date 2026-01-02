#include <iostream>
using namespace std;

int main() {
	
    float temp[7];
	float sum = 0;

    cout << "Enter temperatures for 7 days: " << endl;
    for (int i = 0; i < 7; i++) {
    	cout << "Day " << i + 1 << ": ";
        cin >> temp[i];
        sum += temp[i];
    }

    cout << "Average Temperature: " << sum / 7 << endl;
    return 0;
    
}

