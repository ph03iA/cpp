#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

map<char, pair<int, int>> mp;

bool check(string s, int xx, int yy, string dic)
{
    int x = 0, y = 0;
    int cnt = 0, cnt1 = 0;
    for (char ch : s)
    {
        if (ch == 'H')
        {
            cnt++;
        }
        else
        {
            cnt1++;
        }
    }
    if (cnt == 0 || cnt1 == 0)
    {
        return false;
    }
    for (int i = 0; i < s.size(); i++)
    {
        pair<int, int> move = mp[dic[i]];
        x += move.first;
        y += move.second;
    }
    if (x != xx || y != yy)
    {
        return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;
    }
    return 0;
}
