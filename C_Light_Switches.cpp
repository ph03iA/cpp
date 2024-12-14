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
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    fo(i, n)
    {
        cin >> a[i];
    }

    int mx = max_element(a.begin(), a.end()) - a.begin();
    int val = *max_element(a.begin(), a.end());
    fo(i, n)
    {
        a[i] = val - a[i];
        a[i] %= 2 * k;
        if (a[i] >= k)
            a[i] -= 2 * k;
    }
    int x = *max_element(a.begin(), a.end());
    int m = *min_element(a.begin(), a.end());
    if (x - m >= k)
        cout << -1 << "\n";
    else
    {
        if (m <= 0)
            cout << val - m << "\n";
        else
            cout << val + k * 2 - m << "\n";
    }
}

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t;
        cin >> t;
        while (t--)
        {
            solve();
        }
        return 0;
    }