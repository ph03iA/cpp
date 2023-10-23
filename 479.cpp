#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    map<string, int> m;
    for (int i = 0; i < n - 1;)
    {
        ++m[s.substr(i, 2)];
    }
    int max_val = 0;
    string max_pair = "";
    for (auto x : m)
    {
        if (x.second > max_val)
        {
            max_val = x.second;
            max_pair = x.first;
        }
    }
    cout << max_pair;
}

int main()
{
    solve();
    return 0;
}