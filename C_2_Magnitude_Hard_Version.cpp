#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 998244353;
const int MAX_C = 2e5 + 1;
const int N = 1e6 + 5;
int q, n, mod = 998244353;
int a[N], f1[N], f2[N], w1[N], w2[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        f1[1] = max(a[1], abs(a[1]));
        f2[1] = min(a[1], abs(a[1]));
        if (a[1] >= 0)
        {
            w1[1] = 2;
            w2[1] = 2;
        }
        else
        {
            w1[1] = 1;
            w2[1] = 1;
        }
        for (int i = 2; i < n; i++)
        {
            f1[i] = max({f1[i - 1] + a[i],
                         abs(f1[i - 1] + a[i]),
                         f2[i - 1] + a[i],
                         abs(f2[i - 1] + a[i])});
            if (f1[i] == f1[i - 1] + a[i])
                w1[i] = (w1[i] + w1[i - 1]) % mod;

            if (f1[i] == abs(f1[i - 1] + a[i]))
                w1[i] = (w1[i] + w1[i - 1]) % mod;

            if (f1[i - 1] != f2[i - 1])
            {
            }
            if (f1[i] == f2[i - 1] + a[i])
                w1[i] = (w1[i] + w2[i - 1]) % mod;

            if (f1[i] == abs(f2[i - 1] + a[i]))
                w1[i] = (w1[i] + w2[i - 1]) % mod;
            if (f2[i] == f1[i - 1] + a[i])
                w2[i] = (w2[i] + w1[i - 1]) % mod;
            // cout << w1[i] << " " << w2[i] << endl;
            if (f2[i] == abs(f1[i - 1] + a[i]))
                w2[i] = (w2[i] + w1[i - 1]) % mod;
            // cout << w2[i] << " " << w2[i] << endl;
            if (f1[i - 1] != f2[i - 1])
            {
                if (f2[i] == f2[i - 1] + a[i])
                    w2[i] = (w2[i] + w2[i - 1]) % mod;
                // cout << w1[i] << " " << w2[i] << endl;
                if (f2[i] == abs(f2[i - 1] + a[i]))
                    w2[i] = (w2[i] + w2[i - 1]) % mod;
                // cout << w1[i] << " " << w2[i] << endl;
            }
            cout << w1[n] << "\n";
            for (int i = 1; i <= n; i++)
                w1[i] = w2[i] = 0;
        }
    }