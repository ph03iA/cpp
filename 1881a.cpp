#include<bits/stdc++.h>
using namespace std;
#define int long long int
                    
int32_t main(){
    int t;
    cin>>t;

    while(t--){
        int n, m;
        cin>>n>>m;
        string s1, s2;
        cin>>s1>>s2;

        bool found = false;
        for(int i =0; i<=6; i++){
            if(s1.find(s2) != -1){
                found = true;
                cout<<i<<endl;
                break;
            }
            s1 += s1;
        }
        if(!found) cout <<"-1"<<endl;
    }

}