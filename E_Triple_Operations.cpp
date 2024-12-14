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

const int N = 200000;

vector<int> dp(N + 1, -1);
vector<int> pre(N + 1, 0);

void precompute()
{
    dp[0] = 0;
    for (int i = 1; i <= N; ++i)
    {
        dp[i] = 1 + dp[i / 3];
    }

    pre[0] = dp[0];
    for (int i = 1; i <= N; ++i)
    {
        pre[i] = pre[i - 1] + dp[i];
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();

    int t;
    cin >> t;

    while (t--)
    {
        int l, r;
        cin >> l >> r;

        if (l > r || l < 0 || r > N)
        {
            continue;
        }

        int result = 2 * dp[l] + (pre[r] - pre[l]);
        cout << result << endl;
    }

    return 0;
}