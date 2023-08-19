#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n == 2) {
            cout << "2 1" << endl;
        } else {
            cout << "1 2";
            for (int i = 3; i <= n; ++i) {
                cout << " " << i;
            }
            cout << endl;
        }
    }

    return 0;
}
