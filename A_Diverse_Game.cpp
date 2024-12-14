#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define rep(i, a, b) for(int i = a; i < b; ++i)

int main() {
    fast_io;
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> matrix(n, vector<int>(m));
        
        rep(i, 0, n) {
            rep(j, 0, m) {
                cin >> matrix[i][j];
            }
        }
        
        if (n == 1 && m == 1) {
            cout << -1 << endl;
            continue;
        }
        
        vector<int> ele;
        
        rep(i, 0, n) {
            rep(j, 0, m) {
                ele.pb(matrix[i][j]);
            }
        }
        
        vector<int> rotele;
        rotele.pb(ele.back());
        
        rep(i, 0, ele.size() - 1) {
            rotele.pb(ele[i]);
        }
        
        vector<vector<int>> ans(n, vector<int>(m));
        
        int idx = 0;
        rep(i, 0, n) {
            rep(j, 0, m) {
                ans[i][j] = rotele[idx++];
            }
        }
        
        rep(i, 0, n) {
            rep(j, 0, m) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
