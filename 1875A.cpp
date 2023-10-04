#include <iostream>
using namespace std;
#define ll long long
void solve()
{
    int a, n, x;
    ll b;
    cin >> a >> b >> n;
    while (n--)
        cin >> x, b += min(a - 1, x);
    cout << b << endl;
}
int main()
{
    // ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}