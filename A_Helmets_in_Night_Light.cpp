#include <bits/stdc++.h>
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

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
bool static mycomp(pair<ll, ll> p1, pair<ll, ll> p2)
{
    if (p1.first == p2.first)
    {
        return p1.second > p2.second;
    }
    else
    {
        return p1.first < p2.first;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, p;
        cin >> n >> p;
        vector<ll> a(n), b(n);
        vector<pair<ll, ll>> vp;

        fo(i, n)
        {
            cin >> a[i];
        }
        fo(i, n)
        {
            cin >> b[i];
        }
        fo(i, n)
        {
            vp.pb({min(b[i], p), a[i]});
        }
        if (n == 1)
        {
            cout << p << endl;
            continue;
        }
        sort(begin(vp), end(vp), mycomp);
        ll ans = p;
        ll rem = n - 1;
        fo(i, n-1)
        {
            ans += min(vp[i].second, rem) * vp[i].first;
            rem -= min(rem, vp[i].second);
        }
        cout << ans << endl;
    }
    return 0;
}