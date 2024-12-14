#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    // Precompute powers of 2 up to 20
    vector<ll> power2(21, 1);
    for(int i = 1; i <= 20; i++) 
        power2[i] = min(power2[i-1] * 2, (ll)1000001);
    
    while(T--) {
        string E;
        ll K;
        cin >> E >> K;
        int N = E.size();
        
        // Precompute suffix question marks
        vector<int> suffix_q(N+1, 0);
        for(int i = N - 1; i >= 0; i--) {
            suffix_q[i] = suffix_q[i+1] + (E[i] == '?' ? 1 : 0);
        }
        
        string S = E;
        for(int i = 0; i < N; i++) {
            if(S[i] == '?') {
                int rem_q = suffix_q[i+1];
                ll num_S_with_2;
                
                if(rem_q <= 20) {
                    num_S_with_2 = power2[rem_q];
                } else {
                    num_S_with_2 = 1000001;
                }
                
                if(K <= num_S_with_2) {
                    S[i] = '2';
                } else {
                    S[i] = '1';
                    K -= num_S_with_2;
                }
            }
        }
        
        // Compute number of decodings
        vector<ll> dp(N+1, 0);
        dp[N] = 1;
        
        for(int i = N - 1; i >= 0; i--) {
            if(S[i] != '0') {
                dp[i] += dp[i+1];
                
                if(i + 1 < N) {
                    if(S[i] == '1' || (S[i] == '2' && S[i+1] <= '6')) {
                        dp[i] += dp[i+2];
                    }
                }
            }
            dp[i] %= MOD;
        }
        
        cout << "Case #" << (T+1) << ": " << dp[0] << "\n";
    }
}
