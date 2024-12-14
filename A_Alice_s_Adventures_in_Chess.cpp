#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>



void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    
    int x = 0, y = 0;
    std::string s;
    std::cin >> s;
    
    // Process the string once and check if we reach (a, b)
    for (auto c : s) {
        if (c == 'N') {
            y++;
        } else if (c == 'E') {
            x++;
        } else if (c == 'S') {
            y--;
        } else { // c == 'W'
            x--;
        }

        // If we reach the target, print "YES" and exit the function
        if (x == a && y == b) {
            std::cout << "YES\n";
            return;
        }
    }
    
    // If no solution is found after processing the string, print "NO"
    std::cout << "NO\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
