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
#include <limits.h>
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
    int n;
    cin >> n;
    vector<int> a(n);

    fo(i, n)
    {
        cin >> a[i];
    }

    int maxOdd = INT_MIN, maxEven = INT_MIN;
    fo(i, n)
    {
        if (a[i] % 2 == 0)
        {
            maxEven = max(maxEven, a[i]);
        }
        else
        {
            maxOdd = max(maxOdd, a[i]);
        }
    }

    bool allOdd = true;
    bool allEven = true;

    fo(i, n)
    {
        if (a[i] % 2 != 0)
        {
            allEven = false;
        }
        else
        {
            allOdd = false;
        }
    }

    if (allOdd || allEven)
    {
        cout << 0 << endl;
        return;
    }

    sort(a.begin(), a.end());
    int operations = 0;

    fo(i, n)
    {
        if (a[i] % 2 == 0 && a[i] < maxOdd)
        {
            a[i] += maxOdd;
            maxOdd = max(maxOdd, a[i]);
            operations++;
        }
    }

    allOdd = true;
    allEven = true;

    fo(i, n)
    {
        if (a[i] % 2 != 0)
        {
            allEven = false;
        }
        else
        {
            allOdd = false;
        }
    }

    if (allOdd || allEven)
    {
        cout << operations << endl;
        return;
    }

    fo(i, n)
    {
        if (a[i] % 2 != 0)
        {
            a[i] += maxEven;
            operations++;
            break;
        }
    }

    fo(i, n)
    {
        if (a[i] % 2 == 0)
        {
            operations++;
        }
    }

    cout << operations << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}