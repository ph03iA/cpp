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
    for(int tc = 1; tc <= T; tc++){
        ll W, G, L;
        cin >> W >> G >> L;
        ll E;
        if(L > 0){
            ll a = (W - G) % MOD;
            ll b = ((2 * (L % MOD)) + 1) % MOD;
            E = (a * b) % MOD;
        }
        else{
            E = (W - G) % MOD;
        }
        cout << "Case #" << tc << ": " << E << "\n";
    }
}
