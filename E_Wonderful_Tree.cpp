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

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()
#define nl cout << "\n"
#define co(a)             \
    {                     \
        cout << a << ' '; \
    }
#define cou(a)             \
    {                      \
        cout << a << "\n"; \
    }
#define lcou(v)           \
    {                     \
        for (auto &x : v) \
            co(x);        \
        nl                \
    }
#define cy(x)                         \
    {                                 \
        if (x)                        \
            cou("YES") else cou("NO") \
    }

const int M = 1e9 + 7;
const int N = 5010;

ll n, targ[N][N];
ll inf = 1e18;
vector<ll> e[N];
ll a[N], ans[N];

void dfs(ll x)
{
    if (e[x].empty())
    {
        for (int i = 1; i <= n; i++)
        {
            targ[x][i] = inf;
        }
        ans[x] = 0;
        return;
    }

    ll sums = 0;
    ans[x] = 0;
    for (auto j : e[x])
    {
        dfs(j);
        ans[x] += ans[j];
        sums += a[j];
    }

    ll del = a[x] - sums;
    for (int i = 1; i <= n; i++)
    {
        if (del <= 0)
            break;
        for (auto j : e[x])
        {
            if (del <= 0)
                break;
            if (targ[j][i] <= del)
            {
                ans[x] += i * targ[j][i];
                del -= targ[j][i];
                targ[j][i] = 0;
            }
            else
            {
                ans[x] += i * del;
                targ[j][i] -= del;
                del = 0;
            }
        }
    }

    if (del < 0)
        targ[x][1] = -del;
    for (int i = 2; i <= n; i++)
    {
        ll nsum = 0;
        for (auto j : e[x])
        {
            if (targ[j][i - 1] == inf)
            {
                nsum = inf;
                break;
            }
            nsum += targ[j][i - 1];
        }
        targ[x][i] = nsum;
    }
}

void solve()
{
    cin >> n;
    fo(i, n)
    {
        cin >> a[i];
        e[i].clear();
    }

    fo(i, n)
    {
        ans[i] = 0;
        fo(j, n)
        {
            targ[i][j] = 0;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        ll f;
        cin >> f;
        e[f].push_back(i);
    }

    dfs(1);
    cou(ans[1]);
}

int main()
{

    int TC;
    cin >> TC;
    while (TC--)
    {
        solve();
    }

    return TC;
}