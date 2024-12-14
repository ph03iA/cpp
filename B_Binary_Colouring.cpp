#include <bits/stdc++.h>
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

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

vector<int> solve(unsigned int x)
{
    vector<int> a;
    while (x > 0)
    {
        if (x % 2 == 0)
        {
            a.push_back(0);
        }
        else if ((x & 2) == 0)
        {
            a.push_back(1);
        }
        else
        {
            a.push_back(-1);
            x += 2;
        }
        x >>= 1;
    }
    if (a.empty())
        a.push_back(0);
    return a;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        unsigned int x;
        cin >> x;

        vector<int> a = solve(x);

        cout << a.size() << endl;
        for (int i = 0; i < a.size(); ++i)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
