#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> prefix_sum(const vector<int>& values) {
    int n = values.size();
    vector<int> psum(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        psum[i] = psum[i-1] + values[i-1];
    }
    return psum;
}

bool find_subarray(const vector<int>& psum, int required_sum, int& start, int& end, int start_limit = 0) {
    int n = psum.size() - 1;
    for (int i = start_limit; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (psum[j+1] - psum[i] >= required_sum) {
                start = i;
                end = j;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 0; i < n; ++i) cin >> c[i];

        int tot = accumulate(a.begin(), a.end(), 0);
        int required_sum = (tot + 2) / 3;

        vector<int> psum_a = prefix_sum(a);
        vector<int> psum_b = prefix_sum(b);
        vector<int> psum_c = prefix_sum(c);

        bool found = false;
        vector<string> perms = {"abc", "acb", "bac", "bca", "cab", "cba"};

        for (const auto& perm : perms) {
            int la, ra, lb, rb, lc, rc;

            if (perm == "abc") {
                if (find_subarray(psum_a, required_sum, la, ra) &&
                    find_subarray(psum_b, required_sum, lb, rb, ra + 1) &&
                    find_subarray(psum_c, required_sum, lc, rc, rb + 1)) {
                    cout << la + 1 << " " << ra + 1 << " "
                         << lb + 1 << " " << rb + 1 << " "
                         << lc + 1 << " " << rc + 1 << endl;
                    found = true;
                    break;
                }
            } else if (perm == "acb") {
                if (find_subarray(psum_a, required_sum, la, ra) &&
                    find_subarray(psum_c, required_sum, lc, rc, ra + 1) &&
                    find_subarray(psum_b, required_sum, lb, rb, rc + 1)) {
                    cout << la + 1 << " " << ra + 1 << " "
                         << lc + 1 << " " << rc + 1 << " "
                         << lb + 1 << " " << rb + 1 << endl;
                    found = true;
                    break;
                }
            } else if (perm == "bac") {
                if (find_subarray(psum_b, required_sum, lb, rb) &&
                    find_subarray(psum_a, required_sum, la, ra, rb + 1) &&
                    find_subarray(psum_c, required_sum, lc, rc, ra + 1)) {
                    cout << lb + 1 << " " << rb + 1 << " "
                         << la + 1 << " " << ra + 1 << " "
                         << lc + 1 << " " << rc + 1 << endl;
                    found = true;
                    break;
                }
            } else if (perm == "bca") {
                if (find_subarray(psum_b, required_sum, lb, rb) &&
                    find_subarray(psum_c, required_sum, lc, rc, rb + 1) &&
                    find_subarray(psum_a, required_sum, la, ra, rc + 1)) {
                    cout << lb + 1 << " " << rb + 1 << " "
                         << lc + 1 << " " << rc + 1 << " "
                         << la + 1 << " " << ra + 1 << endl;
                    found = true;
                    break;
                }
            } else if (perm == "cab") {
                if (find_subarray(psum_c, required_sum, lc, rc) &&
                    find_subarray(psum_a, required_sum, la, ra, rc + 1) &&
                    find_subarray(psum_b, required_sum, lb, rb, ra + 1)) {
                    cout << lc + 1 << " " << rc + 1 << " "
                         << la + 1 << " " << ra + 1 << " "
                         << lb + 1 << " " << rb + 1 << endl;
                    found = true;
                    break;
                }
            } else if (perm == "cba") {
                if (find_subarray(psum_c, required_sum, lc, rc) &&
                    find_subarray(psum_b, required_sum, lb, rb, rc + 1) &&
                    find_subarray(psum_a, required_sum, la, ra, rb + 1)) {
                    cout << lc + 1 << " " << rc + 1 << " "
                         << lb + 1 << " " << rb + 1 << " "
                         << la + 1 << " " << ra + 1 << endl;
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            cout << -1 << endl;
        }
    }
    return 0;
}
