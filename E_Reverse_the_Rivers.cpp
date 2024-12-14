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
#define rfo(i, n) for (int i = n - 1; i >= 0; i--)
#define pb push_back

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* UTILS */
#define mod 1000000007
#define pi 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a, int b) { return a < b ? a : b; }
ll max(ll a, int b) { return a > b ? a : b; }

/* Main() function */
void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<vi> a(k + 1, vi(n + 1, 0));

    cfo(i, n) {
        cfo(j, k) {
            int t;
            cin >> t;
            a[j][i] = t | a[j][i - 1];
        }
    }

    while (q--) {
        int m;
        cin >> m;

        vector<pair<int, int>> lc, gc;

        fo(i, m) {
            char sign;
            int r, c;
            cin >> r >> sign >> c;

            if (sign == '<')
                lc.pb(make_pair(r, c));
            else
                gc.pb(make_pair(r, c));
        }

        int crow = 1;

        for (int g = 0; g < gc.size(); g++) {
            int r = gc[g].first;
            int c = gc[g].second;

            int pos = 1;
            while (pos <= n && a[r][pos] <= c) {
                pos++;
            }
            crow = max(crow, pos);
        }

        if (crow > n) {
            cout << -1 << "\n";
            continue;
        }

      
        for (int lp = 0; lp < lc.size(); lp++) {
            int r = lc[lp].first;
            int c = lc[lp].second;
            if (a[r][crow] >= c) {
                cout << -1 << "\n";  
                goto end; 
            }
        }

        cout << crow << "\n"; 

        end:;  
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
