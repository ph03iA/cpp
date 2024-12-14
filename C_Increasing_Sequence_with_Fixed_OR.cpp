#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define pb push_back

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        vector<ll> ans;

        // Start from 1 and go up to n
        for (ll i = 1; i <= n; ++i) {
            // Check if i can be part of the sequence
            if ((i | (i - 1)) == n) {
                ans.pb(i);
            }
        }

        // Output the results
        cout << ans.size() << endl;
        for (ll num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
