#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

bool isWin(int a, int b, int c, int d) {
    int alice = 0, bob = 0;
    if (a > b) alice++;
    else if (a < b) bob++;
    if (c > d) alice++;
    else if (c < d) bob++;
    return alice > bob;
}

int countWins(int a1, int a2, int b1, int b2) {
    vector<int> alice = {a1, a2};
    vector<int> bob = {b1, b2};
    int wins = 0;
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            wins += isWin(alice[0], bob[i], alice[1], bob[1-i]);
        }
    }
    
    return wins;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        cout << countWins(a1, a2, b1, b2) << '\n';
    }
    
    return 0;
}