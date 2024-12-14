#include <bits/stdc++.h>
#define fo(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define ll long long

using namespace std;

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

        // Map (a, b): count of triplets (a, b, c) for any c
        unordered_map<pair<int, int>, int> ab{};
        unordered_map<pair<int, int>, int> bc{};
        unordered_map<pair<int, int>, int> ac{};

        for (int i = 0; i < n - 2; ++i)
        {
            int a_val = a[i];
            int b_val = a[i + 1];
            int c_val = a[i + 2];

            // Update counts based on current triple
            ab[{a_val, b_val}]++;
            bc[{b_val, c_val}]++;
            ac[{a_val, c_val}]++;

            // Add valid combinations based on current element and existing counts
            ans += ac[{a_val, b_val}]; // (a, b) is valid for existing (a, c)
            ans += ab[{a_val, c_val}]; // (a, c) is valid for existing (a, b)
        }

        cout << ans << endl;
    }

    return 0;
}
