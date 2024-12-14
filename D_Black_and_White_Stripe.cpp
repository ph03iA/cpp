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
    {                   //sliding window
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;       

        int b = 0, w = 0;

        fo(i, k)
        {
            if (s[i] == 'B')
            {
                b++;
            }
            else
            {
                w++;
            }
        }
        int ans = w;

        fo(i, n-k)
        {
            if (s[i] == 'B')
            {
                b--;
            }
            else
            {
                w--;
            }
            if (s[i + k] == 'B')
            {
                b++;
            }
            else
            {
                w++;
            }
            ans = min(ans, w);
        }
        cout << ans << endl;
    }
    return 0;
}