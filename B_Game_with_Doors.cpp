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
#define tr(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
#define read(type) readInt<type>() // Fast read

using namespace std;

int gcd(int l, int r)
{
    if (r == 0)
    {
        return l;
    }
    return gcd(r, l % r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int l, r, L, R;
        cin >> l >> r >> L >> R;

        if (L > r || l > R)
        {
            cout << 1 << endl;
            continue;
        }
        if (L > l)
        {
            swap(l, L);
            swap(r, R);
        }

        int ans = 0;
        map<int, int> m;
        for (int i = l; i <= r; i++)
        {
            m[i]++;
        }
        for (int i = L; i <= R; i++)
        {
            m[i]++;
        }

        int x = -1;
        int y = -1;
        for (int i = 1; i <= 100; i++)
        {
            if (m[i] == 2)
            {
                ans++;
                y = i;
                if (x == -1)
                    x = i;
            }
        }

        ans--;
        ans += (min({l, r, L, R}) < x) + (max({l, r, L, R}) > y);

        cout << ans << endl;
    }
    return 0;
}