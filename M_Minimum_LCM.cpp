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
#define rep(i, a, b) for (int i = a; i < b; ++i)
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll lcm = 9e18;
        int x = 1, y = n - 1;
        for (ll d = 2; d * d <= n; d++)
        {
            if (n % d == 0)
            {
                ll a = d;
                ll b = n - a;
                ll lcmV = (a * b) / (gcd(a, b));
                if (lcmV < lcm)
                {
                    lcm = lcmV;
                    x = a;
                    y = b;
                }
                ll a1 = n / d;
                ll b1 = n - a1;
                lcmV = (a1 * b1) / (gcd(a1, b1));
                if (lcmV < lcm)
                {
                    lcm = lcmV;
                    x = a1;
                    y = b1;
                }
            }
        }
        cout << x << " " << y << endl;
    }
    return 0;
}