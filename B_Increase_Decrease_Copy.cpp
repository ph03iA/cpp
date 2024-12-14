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
    return b == 0 ? a : gcd(b, a % b);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n), b(n + 1);

        for (ll &i : a)
            cin >> i;
        for (ll &i : b)
            cin >> i;

        ll val = b.back();
        ll ans = 0;
        bool found = false;
        ll min_add = LLONG_MAX;

        fo(i, n)
        {
            ans += abs(a[i] - b[i]);
            if (val >= min(a[i], b[i]) && val <= max(a[i], b[i]))
            {
                found = true;
            }
            min_add = min({min_add, abs(a[i] - val), abs(b[i] - val)});
        }

        ans += found ? 1 : (min_add + 1);

        cout << ans << endl;
    }

    return 0;
}