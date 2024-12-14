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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    vector<string> results;
    
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        fo(i, n) cin >> a[i];

        if (set<int>(a.begin(), a.end()).size() == 1) {
            results.pb("NO");
        } else {
            results.pb("YES");
            string s(n, 'R');
            s[n-1] = 'B';
            results.pb(s);
        }
    }

    for (const string& result : results) {
        cout << result << '\n';
    }
    
    return 0;
}
