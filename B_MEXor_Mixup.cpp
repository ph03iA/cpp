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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        ll n = a - 1;
        ll x = 0;
        if (n % 4 == 0)
        {
            x = n;
        }
        else if (n % 4 == 1)
        {
            x = 1;
        }
        else if (n % 4 == 2)
        {
            x = n + 1;
        }
        else if (n % 4 == 3)
        {
            x = 0;
        }
        ll l;
        ll y = (x ^ b);
        if (x == b)
        {
            l = a;
        }
        else if (y != a)
        {
            l = a + 1;
        }
        else
        {
            l = a + 2;
        }
        cout << l << endl;
    }
    return 0;
}