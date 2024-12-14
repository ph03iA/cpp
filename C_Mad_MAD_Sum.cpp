#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long sum = 0;

        // Frequency map to count occurrences of each element
        unordered_map<int, int> freq;
        // Max heap to store elements that appear at least twice
        priority_queue<int> maxHeap;

        for (int num : a) {
            ++freq[num];
        }

        // Initialize the max heap with elements that appear at least twice
        for (const auto &entry : freq) {
            if (entry.second > 1) {
                maxHeap.push(entry.first);
            }
        }

        while (true) {
            long long currentSum = 0;
            bool allZero = true;

            // Calculate current sum of the array
            for (int i = 0; i < n; ++i) {
                currentSum += a[i];
            }

            sum += currentSum;

            // If all elements are zero, break the loop
            if (currentSum == 0) {
                break;
            }

            // Find the MAD value
            int maxMAD = 0;
            if (!maxHeap.empty()) {
                maxMAD = maxHeap.top();
            }

            // Update the array with the MAD value and update the frequency map
            unordered_map<int, int> newFreq;
            for (int i = 0; i < n; ++i) {
                a[i] = maxMAD;
                if (a[i] != 0) {
                    allZero = false;
                    ++newFreq[a[i]];
                }
            }

            // Update the max heap with the new frequencies
            while (!maxHeap.empty()) {
                maxHeap.pop();
            }
            for (const auto &entry : newFreq) {
                if (entry.second > 1) {
                    maxHeap.push(entry.first);
                }
            }

            if (allZero) {
                break;
            }
        }

        cout << sum << endl;
    }

    return 0;
}
