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

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;

        vector<vector<int>> pa(26, vector<int>(n + 1, 0));
        vector<vector<int>> pb(26, vector<int>(n + 1, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                pa[j][i + 1] = pa[j][i];
                pb[j][i + 1] = pb[j][i];
            }
            pa[a[i] - 'a'][i + 1]++;
            pb[b[i] - 'a'][i + 1]++;
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;

            int operations = 0;
            for (int i = 0; i < 26; i++)
            {
                int ca = pa[i][r] - pa[i][l - 1];
                int cb = pb[i][r] - pb[i][l - 1];
                operations += abs(ca - cb);
            }

            cout << operations / 2 << '\n';
        }
        }
}