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
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* FUNCTIONS */
#define fo(i, n) for (int i = 0; i < n; i++)
#define cfo(i, n) for (int i = 1; i <= n; i++)
#define rfo(i, n) for (int i = n-1; i >= 0; i--)
#define f(i, s, e) for (int i = s; i <= e; i++)
#define pb push_back
#define eb emplace_back

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* UTILS */
#define mod 1000000007
#define pi 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

/* clang-format on */

/* Main()  function */
bool func(char a, char b, char c)
{
    int freqA = (a == 'A') + (b == 'A') + (c == 'A');
    int freqB = 3 - freqA; // since total frequency is 3
    return freqA > freqB;
}

/* SOLUTION */
void solve()
{
    int n;
    string s, t;
    cin >> n >> s >> t;

    vector<vector<int>> dp(n + 1, vector<int>(5, -1));
    dp[0][0] = 0;

    f(i, 0, n - 1)
    {
        if (i + 3 <= n)
            dp[i + 3][0] = max(dp[i + 3][0], dp[i][0] + func(s[i], s[i + 1], s[i + 2]) + func(t[i], t[i + 1], t[i + 2]));
        if (i + 2 <= n)
        {
            dp[i + 2][3] = max(dp[i + 2][3], dp[i][0] + func(s[i], s[i + 1], t[i]));
            dp[i + 2][1] = max(dp[i + 2][1], dp[i][0] + func(s[i], t[i], t[i + 1]));
        }
        if (i + 1 <= n && i > 0)
        {
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + func(s[i], s[i - 1], t[i]));
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][3] + func(t[i - 1], t[i], s[i]));
        }
        if (i + 2 <= n && i > 0 && i + 1 < n)
            dp[i + 2][4] = max(dp[i + 2][4], dp[i][1] + func(s[i], s[i - 1], s[i + 1]));
        if (i + 1 <= n && i > 1)
            dp[i + 1][3] = max(dp[i + 1][3], dp[i][2] + func(s[i], s[i - 1], s[i - 2]));
        if (i + 2 <= n && i > 0 && i + 1 < n)
            dp[i + 2][2] = max(dp[i + 2][2], dp[i][3] + func(t[i - 1], t[i], t[i + 1]));
        if (i + 1 <= n && i > 1)
            dp[i + 1][1] = max(dp[i + 1][1], dp[i][4] + func(t[i - 2], t[i], t[i - 1]));
    }

    cout << dp[n][0] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}