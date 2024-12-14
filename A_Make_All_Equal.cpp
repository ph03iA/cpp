#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_operations_to_equal(vector<int>& a) {
    int n = a.size();
    
    // If there's only one element, no operation is needed
    if (n == 1) return 0;

    int max_non_increasing = 1, current_length = 1;

    // Loop through the array to find the longest non-increasing subsequence length
    for (int i = 1; i < n; ++i) {
        if (a[i] <= a[i - 1]) {
            ++current_length;
        } else {
            max_non_increasing = max(max_non_increasing, current_length);
            current_length = 1;
        }
    }
    
    // Since the array is cyclic, we should check if the array ends with a non-increasing sequence
    if (a[0] <= a[n - 1]) {
        current_length += (a[0] <= a[n - 1]) ? max_non_increasing : 0;
    }
    
    max_non_increasing = max(max_non_increasing, current_length);

    // The result is n - the length of the longest non-increasing subsequence
    return n - max_non_increasing;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cout << min_operations_to_equal(a) << endl;
    }

    return 0;
}
