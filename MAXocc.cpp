#include<bits/stdc++.h>
using namespace std;
                    
char maxOccurance(string s){
    int arr[26];

    for(int i =0; i<s.length(); i++){
        char ch = s[i];

        if(ch >= 'a' && ch<= 'z'){
            transform(s.begin(), s.end(),s.begin(),::tolower);
        }
        else{
            transform(s.begin(), s.end(),s.begin(),::toupper);
        }
        
    }
    
}

int main(){
    string s;
    cin>>s;
    maxOccurance(s);
    cout<<s<<endl;
    	    
}