#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string stone;
    int count = 0;
    
    
    for(int i = 0; i < n; i++){
        cin>>stone[i];
        if(i > 0){      //second iteration
            if(stone[i-1] == stone[i])
                count++;
        }
    }
    cout<<count;
    return 0;
}