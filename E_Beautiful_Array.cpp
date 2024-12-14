#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <climits>
using namespace std;
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

#define ll long long

void read_input(vector<int> &a, int &n, int &k)
{
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
}

int solve(const vector<int> &a, int n, int k)
{
    map<int, set<int>> mp;

    for (int x : a)
    {
        if (mp[x % k].find(x) != mp[x % k].end())
        {
            mp[x % k].erase(x);
        }
        else
        {
            mp[x % k].insert(x);
        }
    }

    int cnt = 0, val = -1;
    for (auto &x : mp)
    {
        int m = x.S.size();

        if (m % 2 == 1)
        {
            cnt++;
            val = x.F;
        }
    }

    if (cnt > 1)
    {
        return -1;
    }

    int ans = 0;
    for (auto &x : mp)
    {
        if (x.F == val)
        {
            continue;
        }

        vector<int> elements(x.S.begin(), x.S.end());
        int m = elements.size();

        for (int i = 0; i + 1 < m; i += 2)
        {
            ans += (elements[i + 1] - elements[i]) / k;
        }
    }

    if (cnt)
    {
        vector<int> v;
        for (int x : mp[val])
            v.push_back(x);
        int m = v.size();
        if (m == 1)
        {
            return ans;
        }
        vector<int> pref(m, 0), suf(m, 0);
        pref[1] = v[1] - v[0];
        for (int i = 3; i < m; i += 2)
        {
            pref[i] = v[i] - v[i - 1] + pref[i - 2];
        }

        suf[m - 2] = v[m - 1] - v[m - 2];
        for (int i = m - 4; i >= 0; i -= 2)
        {
            suf[i] = v[i + 1] - v[i] + suf[i + 2];
        }
        ll ta = LLONG_MAX;
        for (int i = 0; i < m; i += 2)
        {
            ll x = 0;
            if (i > 0)
            {
                x += pref[i - 1];
            }
            if (i + 1 < m)
            {
                x += suf[i + 1];
            }
            ta = min(ta, x);
        }
        ans += ta / k;
    }

    return ans;
}

void output_result(int result)
{
    cout << result << endl;
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
        vector<int> a;
        read_input(a, n, k);
        int result = solve(a, n, k);
        output_result(result);
    }

    return 0;
}
