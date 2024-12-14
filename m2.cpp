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
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int T;
        cin >> T;
        vector<int> test_cases(T);
        int maxN = 0;
        for (auto &x : test_cases)
        {
            cin >> x;
            maxN = max(maxN, x);
        }
        vector<bool> sieve(maxN + 3, true);
        sieve[0] = sieve[1] = false;
        for (int i = 2; i * i <= maxN + 2; i++)
            if (sieve[i])
            {
                for (int j = i * i; j <= maxN + 2; j += i)
                    sieve[j] = false;
            }
        vector<int> twin_prefix(maxN + 1, 0);
        for (int i = 2; i <= maxN - 2; i++)
            twin_prefix[i] = twin_prefix[i - 1] + (sieve[i] && sieve[i + 2] ? 1 : 0);
        for (int tc = 1; tc <= T; tc++)
        {
            int N = test_cases[tc - 1];
            int twin = (N >= 5) ? (twin_prefix[N - 2]) : 0;
            int count = twin + (twin >= 1 ? 1 : 0);
            cout << "Case #" << tc << ": " << count << "\n";
        }
    }
    return 0;
}