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

ll calculateScore(vector<ll> &a)
{
    int n = a.size();
    ll maxScore = 0;
    fo(i, n)
    {
        vector<ll> c;
        fo(j, n)
        {
            if (j != i)
                c.pb(a[j]);
        }

        sort(c.begin(), c.end());
        ll median = c[(n - 2) / 2];
        maxScore = max(maxScore, a[i] + median);
    }
    return maxScore;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<ll> a(n);
        vector<int> b(n);

        fo(i, n)
        {
            cin >> a[i];
        }

        fo(i, n)
        {
            cin >> b[i];
        }

        int ops = min(k, count(b.begin(), b.end(), 1));

        vector<pair<ll, int>> inc;
        fo(i, n)
        {
            if (b[i] <= 1)
            {
                inc.pb({a[i], i});
            }
        }

        sort(inc.begin(), inc.end());

        for (int i = 0; i < ops; i++)
        {
            int index = inc[inc.size() - 1 - i].second;
            a[index] += k / ops;
            if (i < k % ops)
                a[index]++;
        }

        cout << calculateScore(a) << endl;
    }

    return 0;
}
