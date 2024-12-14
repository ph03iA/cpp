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

        int sum = 0;
        int neg = 0;
        int mini = 1000;
        bool isZero = false;

        fo(i, n)
        {
            fo(i, m)
            {
                int a;
                cin >> a;
                if (a == 0)
                {
                    isZero = true;
                }
                sum += abs(a);
                if (a < 0)
                {
                    neg++;
                }
                mini = min(mini, abs(a));
            }
        }
        if (neg % 2 == 0)
        {
            cout << sum << endl;
        }
        else if (neg % 2 == 1 && isZero)
        {
            cout << sum << endl;
        }
        else
        {
            cout << sum - 2 * mini << endl;
        }
    }
    return 0;
}