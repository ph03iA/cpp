#include <bits/stdc++.h>
using namespace std;

string solve(string s1, char c)
{
    string s = "qwertyuiopasdfghjkl;zxcvbnm,./";
    string ans;
    int n = s.length();
    for(int i = 0; i<n; i++){
        int index = s.find(s1[i]);  //s me s1 ka 1st element dhubd rhe hai 
        if(c == 'R'){
            ans += s[index-1];      //agar R input hai to index me se -1
        }
        else{
            ans += s[index+1];
        }
    }
    return ans;
}

int main()
{
    string s2;
    char c;
    cin>>s2;
    cin>>c;
    cout<<solve(s2, c);

    return 0;
    
}