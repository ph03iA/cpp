#include <iostream>
#include <cmath>
#include <climits>
#define ll long long
#define nl "\n"

using namespace std;

ll calculateSum(ll start, ll end) {
    return (end * (end + 1)) / 2 - (start * (start - 1)) / 2;
}

ll findMinDifference(ll a, ll b) {
    ll c = b + a - 1;
    ll sum = calculateSum(b, c);

    ll minDIff = LLONG_MAX;
    ll csum = 0;

    while (true) {
        csum += c;
        sum -= c;
        c--;

        ll diff = abs(sum - csum);

        if (diff < minDIff) {
            minDIff = diff;
        } else {
            break;
        }
    }

    return minDIff;
}

void solve() {
    ll a, b;
    cin >> a >> b;

    ll minDIff = findMinDifference(a, b);

    cout << minDIff << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
