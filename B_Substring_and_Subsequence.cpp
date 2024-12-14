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
    return b == 0 ? a : gcd(b, a % b);
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size(), result = m;
    
    fo(start, m)
    {
        int j = start;
        fo(i, n)
        {
            if (j < m && s1[i] == s2[j])
                j++;
        }
        result = min(result, start + m - j);
    }
    cout << result + n << '\n';
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
