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

void fill_vector(vector<int> &arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
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
        int n, m;
        cin >> n >> m;
        int size = n + m + 1;
        vector<int> a(size), b(size);

        fill_vector(a, size);
        fill_vector(b, size);

        ll e = 0, et = 0;
        int cd = 0, c = 0;
        vector<int> mark1(size), mark2(size);

        for (int i = 0; i < size; ++i)
        {
            if ((a[i] > b[i] && cd <= n) || c >= m)
            {
                e += a[i];
                cd++;
                mark1[i] = 1;
            }
            else
            {
                e += b[i];
                c++;
                mark1[i] = 0;
            }
        }

        cd = 0;
        c = 0;

        for (int i = 0; i < size; ++i)
        {
            if ((a[i] < b[i] && c <= m) || cd >= n)
            {
                et += b[i];
                c++;
                mark2[i] = 0;
            }
            else
            {
                et += a[i];
                cd++;
                mark2[i] = 1;
            }
        }

        for (int i = 0; i < size; ++i)
        {
            ll v1 = (mark1[i] == 1) ? (e - a[i]) : (et - b[i]);
            cout << v1 << " ";
        }
        cout << endl;
    }

    return 0;
}
