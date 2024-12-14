#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll x;
        cin >> n >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<ll> p(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            p[i] = p[i - 1] + a[i - 1];
        }

        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ll target = p[i] + x;
            auto it = upper_bound(p.begin() + i + 1, p.end(), target);
            int valid_subarrays = it - (p.begin() + i + 1);
            ans += valid_subarrays;
        }

        cout << ans << endl;
    }

    return 0;
}
