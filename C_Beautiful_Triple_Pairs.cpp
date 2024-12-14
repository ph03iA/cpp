#include <bits/stdc++.h>
#define fo(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define ll long long

using namespace std;

bool isValid(const array<int, 3> &t1, const array<int, 3> &t2)
{
    int dif = 0;
    if (t1[0] != t2[0])
        dif++;
    if (t1[1] != t2[1])
        dif++;
    if (t1[2] != t2[2])
        dif++;
    return dif == 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        fo(i, n)
        {
            cin >> a[i];
        }

        ll ans = 0;
        vector<array<int, 3>> triples;

        for (int i = 0; i < n - 2; ++i)
        {
            triples.pb({a[i], a[i + 1], a[i + 2]});
            for (int j = 0; j < i; ++j)
            {
                if (isValid(triples[i], triples[j]))
                {
                    ++ans;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
