#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MXSZ = 2e5 + 5; 
ll a[MXSZ];

void solve() {
    ll n, k;
    cin >> n >> k;

    ll i = 1;
    while (i <= n) {
        cin >> a[i];
        i++;
    }

    sort(a + 1, a + n + 1);
    ll sum = 0, ops = 0;
    i = 1;

    while (i <= n) {
        ll increment = (n - i + 1) * (a[i] - a[i - 1]);
        if (sum + increment >= k) {
            ops += (k - sum);
            break;
        }
        ops += increment + 1; 
        sum += increment;  
        i++;
    }

    cout << ops << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
