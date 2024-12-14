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

ll codn(ll n, ll a, ll b, ll x)
{
    ll y = n - x;
    ll c = b - x;
    return y * a + (b * (b + 1) / 2) - (c * (c + 1) / 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        ll n, a, b;
        cin >> n >> a >> b;

        if (b < a)
        {
            cout << n * a << endl;
            continue;
        }

        ll l = 0, r = min(n, b - a);
        ll ans = 0;

        while (l <= r)
        {
            ll mid = l + (r - l) / 2;
            ll currenta = codn(n, a, b, mid);

            if (currenta > ans)
            {
                ans = currenta;
            }

            ll nextl = codn(n, a, b, mid - 1);
            ll nexta = codn(n, a, b, mid + 1);

            if (nextl > currenta)
            {
                r = mid - 1;
            }
            else if (nexta > currenta)
            {
                l = mid + 1;
            }
            else
            {
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
