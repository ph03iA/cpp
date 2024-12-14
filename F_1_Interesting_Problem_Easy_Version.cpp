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
#define gc getchar_unlocked
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
#define read(type) readInt<type>() // Fast read
using namespace std;

int solve(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n, 0);
    int max_operations = 0;

    for (int i = n - 2; i >= 0; --i) {
        if (a[i] == i + 1) {
            // If we can perform the operation at index i
            dp[i] = 1;
            if (i + 2 < n) {
                dp[i] += dp[i + 2];
            }
            max_operations = max(max_operations, dp[i]);
        } else {
            if (i + 1 < n) {
                dp[i] = dp[i + 1];
            }
        }
    }
    return max_operations;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << solve(a) << endl;
    }
    return 0;
}
