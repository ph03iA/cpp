#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, d, k;
    cin >> n >> d >> k;

    vector<int> job_count(n + 2, 0);

    // Process each job interval
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        job_count[l]++;
        if (r + 1 <= n) job_count[r + 1]--;
    }

    // Compute the prefix sum to get the number of active jobs on each day
    vector<int> active_jobs(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        active_jobs[i] = active_jobs[i - 1] + job_count[i];
    }

    // Compute the number of jobs in any d-day window
    vector<int> jobs_in_window(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        jobs_in_window[i] = jobs_in_window[i - 1] + active_jobs[i];
        if (i > d) {
            jobs_in_window[i] -= active_jobs[i - d];
        }
    }

    // Find the best starting day for brother (max jobs) and mother (min jobs)
    int best_brother_start = -1, best_mother_start = -1;
    int max_jobs = -1, min_jobs = 1e9;

    for (int i = 1; i + d - 1 <= n; i++) {
        int jobs_in_period = jobs_in_window[i + d - 1] - (i > 1 ? jobs_in_window[i - 1] : 0);

        // For brother, we want the maximum jobs overlap
        if (jobs_in_period > max_jobs) {
            max_jobs = jobs_in_period;
            best_brother_start = i;
        }

        // For mother, we want the minimum jobs overlap
        if (jobs_in_period < min_jobs) {
            min_jobs = jobs_in_period;
            best_mother_start = i;
        }
    }

    // Output the result for this test case
    cout << best_brother_start << " " << best_mother_start << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
