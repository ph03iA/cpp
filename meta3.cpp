#include <iostream>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while(T--){
        ll W, G, L;
        cin >> W >> G >> L;
        
        ll result = (W - G) % MOD;
        if(L > 0){
            result = (result * (2 * L + 1) % MOD) % MOD;
        }
        
        static int case_no = 1;
        cout << "Case #" << case_no++ << ": " << result << "\n";
    }
}
