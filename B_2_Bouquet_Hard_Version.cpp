#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n; // Number of flower types
        ll m; // Maximum coins available
        cin >> n >> m;

        vector<int> petals(n); // Petals of each flower type
        vector<int> quantities(n); // Quantities of each flower type

        for (int i = 0; i < n; ++i) {
            cin >> petals[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> quantities[i];
        }

        // Pair petals with quantities and sort by petals
        vector<pair<int, ll>> flowers(n);
        for (int i = 0; i < n; ++i) {
            flowers[i] = {petals[i], quantities[i]};
        }
        sort(flowers.begin(), flowers.end());

        // Sliding window to find the maximum petals
        ll maxPetals = 0;
        ll currentCost = 0;
        ll currentPetals = 0;
        int start = 0;

        for (int end = 0; end < n; ++end) {
            // Add the current flower to the window
            currentPetals += flowers[end].first * flowers[end].second;
            currentCost += flowers[end].first * flowers[end].second;

            // Maintain the cost within the budget
            while (currentCost > m) {
                currentCost -= flowers[start].first * flowers[start].second;
                currentPetals -= flowers[start].first * flowers[start].second;
                ++start;
            }

            // Update the maximum petals found
            maxPetals = max(maxPetals, currentPetals);
        }

        cout << maxPetals << endl;
    }

    return 0;
}
