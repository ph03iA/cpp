#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Solution for a single test case
int solve_test_case(int n, int m, ll L, 
                    const vector<pair<ll, ll>>& hurdles,
                    const vector<pair<ll, ll>>& powerups) {
    // Group powerups by position
    map<ll, vector<ll>> powerups_by_pos;
    for (const auto& [x, v] : powerups) {
        powerups_by_pos[x].push_back(v);
    }
    
    // State: {powerups_used, {position, jump_power}}
    // Using priority queue to get minimum powerups solution
    priority_queue<pair<int, pair<ll, ll>>, 
                  vector<pair<int, pair<ll, ll>>>,
                  greater<>> pq;
    ll start_pos = 1;
    pq.push({0, {start_pos, 1}}); // {powerups_used, {position, jump_power}}
    
    // Track visited states to avoid cycles
    set<pair<ll, ll>> seen; // {position, jump_power}
    
    // Check if a jump between positions crosses any hurdles
    auto can_jump_to = [&](ll from_pos, ll to_pos) -> bool {
        if (to_pos > L) return false;
        for (const auto& [l, r] : hurdles) {
            // If jump path intersects with hurdle interval
            if (from_pos <= r && to_pos >= l) {
                return false;
            }
        }
        return true;
    };
    
    while (!pq.empty()) {
        auto [powerups_used, state] = pq.top();
        auto [pos, jump_power] = state;
        pq.pop();
        
        // Reached the target
        if (pos == L) {
            return powerups_used;
        }
        
        // Skip if we've seen this state
        if (seen.count({pos, jump_power})) {
            continue;
        }
        seen.insert({pos, jump_power});
        
        // Try jumping without taking any new powerups
        for (ll new_pos = pos + 1; new_pos <= min(pos + jump_power, L); new_pos++) {
            if (can_jump_to(pos, new_pos)) {
                pq.push({powerups_used, {new_pos, jump_power}});
            }
        }
        
        // Try taking powerups at current position
        auto it = powerups_by_pos.find(pos);
        if (it != powerups_by_pos.end()) {
            for (ll power_value : it->second) {
                ll new_jump_power = jump_power + power_value;
                // Try jumping with new power
                for (ll new_pos = pos + 1; new_pos <= min(pos + new_jump_power, L); new_pos++) {
                    if (can_jump_to(pos, new_pos)) {
                        pq.push({powerups_used + 1, {new_pos, new_jump_power}});
                    }
                }
            }
        }
    }
    
    return -1; // Cannot reach target
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        ll L;
        cin >> n >> m >> L;
        
        vector<pair<ll, ll>> hurdles(n);
        for (int i = 0; i < n; i++) {
            cin >> hurdles[i].first >> hurdles[i].second;
        }
        
        vector<pair<ll, ll>> powerups(m);
        for (int i = 0; i < m; i++) {
            cin >> powerups[i].first >> powerups[i].second;
        }
        
        cout << solve_test_case(n, m, L, hurdles, powerups) << '\n';
    }
    
    return 0;
}