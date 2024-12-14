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
ll min(ll a, int b) { return (a < b) ? a : b; }
ll min(int a, ll b) { return (a < b) ? a : b; }
ll max(ll a, int b) { return (a > b) ? a : b; }
ll max(int a, ll b) { return (a > b) ? a : b; }
ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
string to_upper(string a) { for (char &c : a) if (c >= 'a' && c <= 'z') c -= 'a' - 'A'; return a; }
string to_lower(string a) { for (char &c : a) if (c >= 'A' && c <= 'Z') c += 'a' - 'A'; return a; }
bool prime(ll a) { if (a == 1) return false; for (int i = 2; i <= round(sqrt(a)); ++i) if (a % i == 0) return false; return true; }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

/* Recursive Functions */
ll recSum(const vector<int> &a, int index) {
    if (index < 0) return 0;
    return a[index] + recSum(a, index - 1);
}

int rec(const vector<int> &a, int index) {
    if (index < 0) return 0;
    return a[index] / 2 + rec(a, index - 1);
}

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

/* clang-format on */

/* Main()  function */
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;
        vi a(n);
        fo(i, n)
        {
            cin >> a[i];
        }

        ll y = recSum(a, n - 1);

        int ans = 0;
        int z = 2 * r - y;

        ans += min(z, y);
        int x = y - ans;

        int pairs = rec(a, n - 1);

        ans += 2 * min(pairs, x / 2);
        cout << ans << endl;
    }
    return 0;
}
