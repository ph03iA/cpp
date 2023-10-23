#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<char, int> pos;

void solve()
{
    string n;
    cin >> n;

    char p = '1';
    int ans = 0; // Initialize ans to 0
    for (auto x : n)
    {
        ans += abs(pos[p] - pos[x]);
        p = x;
    }
    cout << ans << endl;
}

int main()
{
    // Initialize pos['0'] to 0
    pos['0'] = 0;

    for (int i = '1'; i <= '9'; i++)
    {
        pos[i] = i - '0';
    }

    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
