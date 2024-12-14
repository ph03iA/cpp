#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#define gc getchar_unlocked
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
#define read(type) readInt<type>() // Fast read

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

void readInput(int &n, int &m, string &s, vector<int> &a, string &s2)
{
    cin >> n >> m >> s;
    a.resize(m);
    for (int &pos : a)
        cin >> pos;
    cin >> s2;
}

string processString(int m, const vector<int> &a, string s, string s2)
{
    sortall(s2);

    map<int, int> mp;
    for (int pos : a)
        mp[pos]++;

    int extra = 0;
    for (const auto &it : mp)
        extra += it.second - 1;

    s2 = s2.substr(0, m - extra);

    int i = 0;
    for (const auto &it : mp)
        s[it.first - 1] = s2[i++];

    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        string s, s2;
        vector<int> a;

        readInput(n, m, s, a, s2);
        cout << processString(m, a, s, s2) << endl;
    }

    return 0;
}