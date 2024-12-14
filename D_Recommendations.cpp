#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct User {
    long long l, r;
};

int main() {
    int t;
    cin >> t; // Read number of test cases
    while (t--) {
        int n;
        cin >> n; // Read number of users
        vector<User> users(n);
        vector<long long> recommendedTracks(n, 0);
        
        for (int i = 0; i < n; ++i) {
            cin >> users[i].l >> users[i].r; // Read the liked track segments
        }
        
        for (int i = 0; i < n; ++i) {
            vector<long long> predictors;
            long long maxR = -1;
            bool hasPredictor = false;

            for (int j = 0; j < n; ++j) {
                if (i != j && users[j].l <= users[i].l && users[j].r >= users[i].r) {
                    predictors.push_back(j);
                    maxR = max(maxR, users[j].r);
                    hasPredictor = true;
                }
            }

            if (!hasPredictor) {
                recommendedTracks[i] = 0;
                continue;
            }

            // Calculate strongly recommended tracks
            long long totalRecommended = 0;
            for (long long track = users[i].l; track <= maxR; ++track) {
                bool isRecommended = true;
                for (long long predictor : predictors) {
                    if (track >= users[predictor].l && track <= users[predictor].r) {
                        isRecommended = false;
                        break;
                    }
                }
                if (isRecommended) {
                    totalRecommended++;
                }
            }
            
            recommendedTracks[i] = totalRecommended;
        }

        // Output results for this test case
        for (const auto& count : recommendedTracks) {
            cout << count << " ";
        }
        cout << endl;
    }
    return 0;
}