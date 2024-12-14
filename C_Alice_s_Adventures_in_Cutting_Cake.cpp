#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>

ll calculatePrefixSum(int k, int start, vll &a, int n, int m, ll v, vll &prefixSum, vi &lastIndex) {
    if (k > m) return LLONG_MAX;
    if (start >= n) {
        prefixSum[k] = LLONG_MAX;
        lastIndex[k] = n;
        return prefixSum[k];
    }

    ll currentSum = 0;
    int end = start;
    while (end < n && currentSum < v) {
        currentSum += a[end++];
    }

    if (currentSum >= v) {
        prefixSum[k] = (k > 0 ? prefixSum[k - 1] : 0) + currentSum;
        lastIndex[k] = end - 1;
        return calculatePrefixSum(k + 1, end, a, n, m, v, prefixSum, lastIndex);
    } else {
        prefixSum[k] = LLONG_MAX;
        lastIndex[k] = n;
        return prefixSum[k];
    }
}

ll calculateSuffixSum(int k, int end, vll &a, int n, int m, ll v, vll &suffixSum, vi &firstIndex) {
    if (k > m) return LLONG_MAX;
    if (end < 0) {
        suffixSum[k] = LLONG_MAX;
        firstIndex[k] = -1;
        return suffixSum[k];
    }

    ll currentSum = 0;
    int start = end;
    while (start >= 0 && currentSum < v) {
        currentSum += a[start--];
    }

    if (currentSum >= v) {
        suffixSum[k] = (k > 0 ? suffixSum[k - 1] : 0) + currentSum;
        firstIndex[k] = start + 1;
        return calculateSuffixSum(k + 1, start, a, n, m, v, suffixSum, firstIndex);
    } else {
        suffixSum[k] = LLONG_MAX;
        firstIndex[k] = -1;
        return suffixSum[k];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        ll v;
        cin >> n >> m >> v;

        vll a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        vll prefixSum(m + 1, LLONG_MAX), suffixSum(m + 1, LLONG_MAX);
        vi lastIndex(m + 1, -1), firstIndex(m + 1, n);

        prefixSum[0] = suffixSum[0] = 0;
        lastIndex[0] = -1;
        firstIndex[0] = n;

        calculatePrefixSum(1, 0, a, n, m, v, prefixSum, lastIndex);
        calculateSuffixSum(1, n - 1, a, n, m, v, suffixSum, firstIndex);

        ll totalSum = 0;
        for (int i = 0; i < n; ++i) totalSum += a[i];
        
        ll maxResult = -1;
        for (int k = 0; k <= m; ++k) {
            if (prefixSum[k] == LLONG_MAX || suffixSum[m - k] == LLONG_MAX) continue;

            if ((k == 0 || m - k == 0 || lastIndex[k] < firstIndex[m - k])) {
                ll currentSum = prefixSum[k] + suffixSum[m - k];
                maxResult = max(maxResult, totalSum - currentSum);
            }
        }

        cout << (maxResult >= 0 ? maxResult : -1) << '\n';
    }

    return 0;
}
