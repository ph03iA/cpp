#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define PII pair<int, int>

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<PII> swaps;

    int zero_end = 0;
    int two_start = n - 1;

    for (int i = 0; i < n; i++)
    {
        if (i < zero_end || i > two_start)
            continue;

        if (a[i] == 0)
        {
            if (i != zero_end)
            {
                swaps.push_back({zero_end + 1, i + 1});
                swap(a[i], a[zero_end]);
            }
            zero_end++;
        }
        else if (a[i] == 2)
        {

            while (two_start > i && a[two_start] == 2)
                two_start--;

            if (i != two_start)
            {
                swaps.push_back({i + 1, two_start + 1});
                swap(a[i], a[two_start]);
            }
            two_start--;

            i--;
        }
    }

    // Output results
    cout << swaps.size() << endl;
    for (const auto &swap : swaps)
    {
        cout << swap.first << " " << swap.second << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}