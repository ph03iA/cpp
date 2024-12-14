#include <iostream>
#include <cmath>

using namespace std;

void handleOddCase(int n) {
    cout << n << endl;
    for (int i = 2; i < n - 1; i++) {
        if (i != 3) {
            cout << i << " ";
        }
    }
    cout << "3 1 " << n - 1 << " " << n << endl;
}

void handleEvenCase(int n, int power_of_two) {
    if (n == 6) {
        cout << "7\n1 2 4 6 5 3\n";
        return;
    }

    int max_value = (1 << (power_of_two + 1)) - 1; 
    cout << max_value << endl;

    int x = (1 << power_of_two);  
    int y = x - 1;

    for (int i = 1; i <= n; i++) {
        if (i != x && i != y && i != 1 &&
            i != x - 2 && i != 3) {
            cout << i << " ";
        }
    }
    cout << "3 1 " << x - 2 << " " << y << " " << x << endl;
}

int calculatePowerOfTwo(int n, int power_of_two = 0) {
    if (pow(2, power_of_two) <= n) {
        return calculatePowerOfTwo(n, power_of_two + 1);
    }
    return power_of_two - 1;
}

void solve() {
    int t;
    cin >> t;  

    while (t--) {
        int n;
        cin >> n;  
        
        if (n % 2 == 1) {
            handleOddCase(n);
        } else {
            int power_of_two = calculatePowerOfTwo(n);
            handleEvenCase(n, power_of_two);
        }
    }
}

int main() {
    solve();
    return 0;
}
