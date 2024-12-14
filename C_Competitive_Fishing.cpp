#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
#include <deque>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <stack>
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
#define fo(j, n) for (int j = 0; j < n; j++)
#define cfo(j, n) for (int j = 1; j <= n; j++)
#define rfo(j, n) for (int j = n-1; j >= 0; j--)
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
string to_upper(string a) { for (int j=0;j<(int)a.size();++j) if (a[j]>='a' && a[j]<='z') a[j]-='a'-'A'; return a; }
string to_lower(string a) { for (int j=0;j<(int)a.size();++j) if (a[j]>='A' && a[j]<='Z') a[j]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int j=2;j<=round(sqrt(a));++j) if (a%j==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

/* clang-format on */
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    stack<ll> suff;
    ll c = 0;

    rfo(j, n)
    {
        suff.push(c);
        if (s[j] == '1')
        {
            c++;
        }
        else
        {
            c--;
        }
    }

    vll suffVec;
    while (!suff.empty())
    {
        suffVec.push_back(suff.top());
        suff.pop();
    }

    sort(suffVec.rbegin(), suffVec.rend());

    ll pre = 0;
    int ans = -1;

    fo(j, suffVec.size())
    {
        pre += suffVec[j];
        if (pre >= k)
        {
            ans = j + 2;
            break;
        }
    }

    cout << ans << endl;
}
/* Main()  function */
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
        solve();
    }
    return 0;
}