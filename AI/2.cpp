#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n; 
    cin.ignore(); 
    for (int i = 0; i < n; i++) {
        string x;
        getline(cin, x);  // Read the entire line as a string

        // Handle special cases
        if (x == "+0" || x == "-0" || x == "0") {
            cout << "inf" << endl;
        } else if (x == "inf" || x == "+inf" || x == "Inf" || x == "+Inf") {
            cout << "0" << endl;
        } else if (x == "nan" || x == "NaN" || x == "NAN") {
            cout << "NaN" << endl;
        } else {
            // Convert string to double
            double num = stod(x);
            if (num == 0.0) {  // Additional check for zero-like inputs
                cout << "inf" << endl;
            } else {
                double reciprocal = 1.0 / num;
                // Output with 6 digits of precision, allowing scientific notation
                cout << scientific << setprecision(6) << reciprocal << endl;
            }
        }
    }
    return 0;
}