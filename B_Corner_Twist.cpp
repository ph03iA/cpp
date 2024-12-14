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

void transform(vector<vector<int>> &a, int i, int j)
{

    a[i][j] = (a[i][j] + 1) % 3;
    a[i + 1][j + 1] = (a[i + 1][j + 1] + 1) % 3;
    a[i + 1][j] = (a[i + 1][j] + 2) % 3;
    a[i][j + 1] = (a[i][j + 1] + 2) % 3;
}

bool canTransform(vector<vector<int>> &a, vector<vector<int>> &b, int n, int m)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < m - 1; ++j)
        {
            while (a[i][j] != b[i][j])
            {
                transform(a, i, j);
            }
        }
    }
    return a == b;
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
        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<int>> b(n, vector<int>(m));

        fo(i, n)
        {
            string row;
            cin >> row;
            for (int j = 0; j < m; ++j)
            {
                a[i][j] = row[j] - '0';
            }
        }

        fo(i, n)
        {
            string row;
            cin >> row;
            for (int j = 0; j < m; ++j)
            {
                b[i][j] = row[j] - '0';
            }
        }

        if (canTransform(a, b, n, m))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
