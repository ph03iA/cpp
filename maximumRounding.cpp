#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
      
        int j = s.size();
        for(int i = s.size()-1;i>=0;i--){
            if(s[i]>='5'){
                s[i] = '0';
                if(i==0){
                    s = '1'+s;
                }
                else{
                s[i-1]++;
            }
            while(j>i){
                s[j] ='0';
                j--;
            }
        }
           
        }
        cout<<s<<endl;
    }
}