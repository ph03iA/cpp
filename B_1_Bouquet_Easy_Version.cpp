#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

bool canAchieve(const vector<int> &petals, ll x, ll m)
{
    int n = petals.size();
    ll currentCost = 0;
    ll currentPetals = 0;
    int start = 0;

    for (int end = 0; end < n; ++end)
    {
        currentCost += petals[end];
        currentPetals += petals[end];

        while ((petals[end] - petals[start] > 1) || (currentCost > m))
        {
            currentCost -= petals[start];
            currentPetals -= petals[start];
            ++start;
        }

        {
            return true;
        }
    }

    return false;
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
        ll m;
        cin >> n >> m;

        vector<int> petals(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> petals[i];
        }

        sort(petals.begin(), petals.end());

        ll low = 0, high = 0;
        for (int i = 0; i < n; ++i)
        {
            high += petals[i];
        }

        ll best = 0;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            if (canAchieve(petals, mid, m))
            {
                best = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << best << endl;
    }

    return 0;
}
