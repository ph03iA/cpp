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

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> m(n);
        fo(i, n)
        {
            int h;
            cin >> h;
            int rh = h % k;
            if (rh == 0)
            {
                rh = k;
            }
            m[i] = mp(rh, i + 1);
        }

        sort(m.begin(), m.end(), compare);
        fo(i, n)
        {
            if (i > 0)
                cout << " ";
            cout << m[i].S;
        }
        cout << endl;
    }
    return 0;
}
