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
        int n, m;
        cin >> n >> m;
        int a[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int ans = 0;
                int f = 1;

                if ((i - 1 >= 0 && a[i][j] <= a[i - 1][j]) ||
                    (j - 1 >= 0 && a[i][j] <= a[i][j - 1]) ||
                    (i + 1 < n && a[i][j] <= a[i + 1][j]) ||
                    (j + 1 < m && a[i][j] <= a[i][j + 1]))
                {
                    f = 0;
                }

                if (i - 1 >= 0)
                {
                    ans = max(ans, a[i - 1][j]);
                }
                if (j - 1 >= 0)
                {
                    ans = max(ans, a[i][j - 1]);
                }
                if (i + 1 < n)
                {
                    ans = max(ans, a[i + 1][j]);
                }
                if (j + 1 < m)
                {
                    ans = max(ans, a[i][j + 1]);
                }

                if (f == 1)
                {
                    a[i][j] = ans;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}
