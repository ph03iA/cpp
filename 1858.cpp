#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        // Determine the winner based on the described rules
        if (a > b) {
            swap(a, b); // Make sure a <= b
        }

        if (b > 2 * a) {
            cout << "Second" << endl;
        } else {
            cout << "First" << endl;
        }
    }

    return 0;
}
