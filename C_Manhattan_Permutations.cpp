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
const int N = 2e5 + 5;

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
        int m, vis[N], a[N], x;
        int n, k;
        cin >> n >> k;
        if (n & 1)
        {
            m = m = (1ll * n * n - 1ll) / 2ll;
        }
        else
        {
            m = 1ll * n * n / 2ll;
        }
        if (k > m || (k & 1))
        {
            cout << "NO" << endl;
            continue;
        }
        fo(i, n)
        {
            vis[i] = 0, a[i] = -1;
        }
        fo(i, n / 2)
        {
            if (!k)
            {
                x = n - i + 1;
                if (k < 2ll * (x - i) && k)
                {
                    x = i + (k / 2);
                }
                swap(a[i], a[x]), k -= 2ll * (x - i);
            }
        }
        cout << "YES" << endl;
        fo(i, n)
        {
            cout << a[i] << endl;
        }
    }
    return 0;
}