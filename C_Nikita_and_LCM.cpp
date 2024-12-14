#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define read(a)       \
    for (auto &i : a) \
    cin >> i

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n);
        read(a);
        sort(a.begin(), a.end());
        map<int, int> m;
        for (auto it : a)
            m[it]++;
        int ans = 0;
        for (auto it = m.rbegin(); it != m.rend(); it++)
        {
            int cur = it->first;
            int len = it->second;
            int f = 0;
            for (auto jt = next(it); jt != m.rend(); jt++)
            {
                int lc = cur * jt->first / __gcd(cur, jt->first);
                if (lc > a.back())
                {
                    f = 1;
                    len = n;
                    break;
                }
                if (m.find(lc) != m.end() && lc != cur)
                    continue;
                len += jt->second;
                cur = lc;
                if (m.find(cur) == m.end())
                    ans = max(ans, len);
            }
            if (f)
            {
                ans = n;
                break;
            }
            if (len == 1 || m.find(cur) != m.end())
                continue;
            ans = max(ans, len);
            if (ans == n)
                break;
        }
        cout << ans << endl;
    }
    return 0;
}
