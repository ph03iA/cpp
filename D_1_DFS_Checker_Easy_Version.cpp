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

vector<int> adj[65536];
int f[65536], pos[65536], p[65536], bad;
set<int> s[65536];

void dfs(int u, int parent) {
    f[u] = 1;
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        f[u] += f[v];
    }
}

bool calc(int u) {
    if (s[u].empty()) return false;
    int max_pos = *prev(s[u].end());
    int min_pos = *s[u].begin();
    return (pos[u] < min_pos || pos[u] > max_pos);
}

void del(int u) {
    if (calc(u)) --bad;
    s[p[u]].erase(u);
    if (calc(u)) ++bad;
}

void add(int u) {
    if (calc(u)) --bad;
    s[p[u]].insert(u);
    if (calc(u)) ++bad;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
            s[i].clear();
        }
        
        for (int i = 2; i <= n; ++i) {
            int a;
            cin >> a;
            adj[a].push_back(i);
            adj[i].push_back(a);
        }

        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
            pos[p[i]] = i;
        }

        dfs(1, 0);
        
        bad = 0;
        for (int i = 1; i <= n; ++i) {
            for (int v : adj[i]) {
                if (pos[i] > pos[v]) s[i].insert(v);
            }
            if (calc(i)) ++bad;
        }

        while (q--) {
            int x, y;
            cin >> x >> y;
            swap(p[x], p[y]);
            swap(pos[p[x]], pos[p[y]]);
            for (int u : {x, y}) {
                for (int v : adj[u]) del(v);
                del(u);
            }
            for (int u : {x, y}) {
                for (int v : adj[u]) add(v);
                add(u);
            }
            cout << (bad == 0 ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}
