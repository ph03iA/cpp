#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

// Custom comparator function to check if combining elements is beneficial
inline bool canCombine(int x, int y, int shift) {
    return (shift > 30) || (x < (y << shift));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        // Precompute powers of 2 modulo MOD
        vector<long long> pow2(n * 32 + 1, 1);
        for (int i = 1; i < pow2.size(); ++i) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        long long ans = 0;
        vector<pair<int, int>> val;

        for (int i = 0; i < n; ++i) {
            int x = a[i], shifts = 0;

            // Reduce x by powers of 2 and count shifts
            while (x % 2 == 0) {
                x /= 2;
                shifts++;
            }

            // Consolidate with previous values if advantageous
            while (!val.empty() && canCombine(val.back().first, x, shifts)) {
                int prev_x = val.back().first;
                int prev_shifts = val.back().second;

                ans = (ans - prev_x * pow2[prev_shifts] % MOD + MOD) % MOD;
                shifts += prev_shifts;
                val.pop_back();
            }

            val.push_back({x, shifts});
            ans = (ans + x * pow2[shifts]) % MOD;

            cout << ans << ' ';
        }
        cout << '\n';
    }
    return 0;
}
