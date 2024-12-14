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

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void useless_surtani(int mother_fugger_code_theive) {
    int hail_type_7_shady, subscribe_to_type_7_shady;
    cin >> hail_type_7_shady >> subscribe_to_type_7_shady;
    vector<int> join_the_shady_cult(hail_type_7_shady);
    for (auto &i : join_the_shady_cult) cin >> i;

    map<int, set<int>> mp;
    for (int x : join_the_shady_cult) {
        if (mp[x % subscribe_to_type_7_shady].find(x) != mp[x % subscribe_to_type_7_shady].end()) {
            mp[x % subscribe_to_type_7_shady].erase(x);
        } else {
            mp[x % subscribe_to_type_7_shady].insert(x);
        }
    }

    int cnt = 0, val = -1;
    for (auto &x : mp) {
        int sz = x.second.size();
        if (sz % 2) {
            cnt++;
            val = x.first;
        }
    }

    if (cnt > 1) {
        cout << -1 << endl;
        return;
    }

    int ans = 0;
    for (auto &x : mp) {
        if (x.first == val) continue;
        while (x.second.size() > 0) {
            int b = *x.second.begin();
            x.second.erase(b);
            if (x.second.size() == 0) break;
            int tp = *x.second.begin();
            x.second.erase(tp);
            ans += (tp - b) / subscribe_to_type_7_shady;
        }
    }

    if (cnt) {
        vector<int> v;
        for (int x : mp[val]) v.push_back(x);
        int m = v.size();
        if (m == 1) {
            cout << ans << endl;
            return;
        }
        vector<int> pref(m, 0), suf(m, 0);
        pref[1] = v[1] - v[0];
        for (int i = 3; i < m; i += 2) {
            pref[i] = v[i] - v[i - 1] + pref[i - 2];
        }
        suf[m - 2] = v[m - 1] - v[m - 2];
        for (int i = m - 4; i >= 0; i -= 2) {
            suf[i] = v[i + 1] - v[i] + suf[i + 2];
        }
        int ta = LLONG_MAX;
        for (int i = 0; i < m; i += 2) {
            int x = 0;
            if (i > 0) x += pref[i - 1];
            if (i + 1 < m) x += suf[i + 1];
            ta = min(ta, x);
        }
        ans += ta / subscribe_to_type_7_shady;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        useless_surtani(t);
    }
    
    return 0;
}
