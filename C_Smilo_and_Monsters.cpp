#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define vll vector<long long>
#define fo(i, n) for (int i = 0; i < n; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vll a(n);
        ll totalMonsters = 0;
        
        fo(i, n) {
            cin >> a[i];
            totalMonsters += a[i];
        }

        
        ll idealOps = (totalMonsters) / 2;  

        sort(a.begin(), a.end());
        int i = 0, j = n - 1;
        ll x = 0;
        ll ans = 0;

        while (i < j) {
            if (x < a[j]) {
                x += a[i];
                ans += a[i];
                i++;
            } else {
                ans++;
                x = 0;
                j--;
            }
        }
        
        
        ans += a[i];
        cout << max(ans, idealOps) << endl;
    }
    return 0;
}
