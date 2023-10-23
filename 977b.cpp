#include<bits/stdc++.h>
using namespace std;
                    
int main(){
    string ss;
    int max = 0;
    string s;
    int n;
    cin>>n;
    cin>>s;
    for(int i = 0; i<n-1; i++){
        string t = s.substr(i, 2);
        int ans = 1;
        for(int j = i+1; j<n-1; j++){
            string tmp = s.substr(j, 2);
            if(t == tmp)
                ans++;
        }
        if(ans>max)
            ss = t, max = ans;

    }
    cout<<ss<<endl;	    
}