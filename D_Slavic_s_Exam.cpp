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

string solve(string s, string t)
{
    int slen = s.length(), tlen = t.length();
    int x = 0;

    for (int i = 0; i < slen && x < tlen; i++)
    {
        if (s[i] == '?')
        {
            s[i] = t[x];
            x++;
        }
        else if (s[i] == t[x])
        {
            x++;
        }
    }

    if (x == tlen)
    {

        for (char &c : s)
        {
            if (c == '?')
                c = 'a';
        }
        return s;
    }

    return "NO";
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    while (T--)
    {
        string s, t;
        cin >> s >> t;

        string result = solve(s, t);
        if (result == "NO")
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl
                 << result << endl;
        }
    }

    return 0;
}