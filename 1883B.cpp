#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{   
    ios;
    #ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("/Users/sreejith/Desktop/output.txt", "w", stdout);
    #endif
    ll t;
    cin>>t;
    while(t--) {
        ll n,ans=0;
        cin>>n;
        string s;
        vector < string > v;
        for(ll i = 0 ; i < n ; i++) {
            cin>>s;
            v.push_back(s);
        }
        for(ll i = 0 ; i < (n/2); i++) {
            for(ll j = 0 ; j < (n/2); j++) {
                vector < ll > res;
                res.push_back(v[i][j] - 'a');
                res.push_back(v[j][n-1-i] - 'a');
                res.push_back(v[n-1-i][n-1-j] - 'a');
                res.push_back(v[n-1-j][i] - 'a');
                sort(res.begin(),res.end());
                for(ll k = 0 ; k < 3 ; k++) {
                    ans+=res[3]-res[k];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;     
 }