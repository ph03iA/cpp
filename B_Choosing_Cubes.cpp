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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, f, k;
        cin >> n >> f >> k;
        vector<int> a(n);
        fo(i, n)
        {
            cin >> a[i];
        }

        int favv = a[f - 1];

        sort(a.begin(), a.end(), greater<int>());

        int cg = 0;
        fo(i, n)
        {
            if (a[i] > favv)
            {
                cg++;
            }
        }

        if (cg >= k)
        {
            cout << "NO" << endl;
        }
        else
        {
            int rp = k - cg;
            int fav = 0;
            fo(i, n)
            {
                if (a[i] == favv)
                {
                    fav++;
                }
            }
            if (rp < fav)
            {
                cout << "MAYBE" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}