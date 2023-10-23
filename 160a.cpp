#include<bits/stdc++.h>
using namespace std;
                    
int main(){
    
        int n;
        cin>>n;

        vector<int> coins(n);
        for(int i = 0; i<n; i++){
            cin>>coins[i];
        }

        int sum = accumulate(coins.begin(), coins.end(), 0);
        sort(coins.begin(), coins.end(), greater<int> ());

        int value = 0;
        bool flag = false;

        for(int i = 0; i<n; i++){
            if(value > sum - value){
                cout << i << endl;
                flag = true;
                break;
            }
            else{
                value += coins[i];
            }
        }
        if(!flag){
            cout << coins.size() << endl;
        }
        return 0;
    }    
