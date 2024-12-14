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
bool pos(ll mid, vi &a, ll c, ll d)
{
    ll score = 0;
    ll n = a.size();
    fo(i, d)
    {
        if (i % mid < n)
        {
            score += a[i % mid];
        }
    }
    return score >= c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    //  freopen("output.txt","w",stdout);
    // #endif

    int t;
    cin >> t;
    while (t--)
    {
        ll n = 1, c = 0, d = 0;
        string s;
        cin >> n >> c >> d;

        vi a(n);
        fo(i, n)
        {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        ll lo = 1, hi = d+2;
        ll ans = -1;
        while (lo <= hi)
        {
            ll mid = (lo + hi) >> 1;
            if (pos(mid, a, c, d))
            {
                lo = mid + 1;
                ans = mid - 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        if (ans >= d)
        {
            cout << "Infinity" << endl;
        }
        else if (ans == -1)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}