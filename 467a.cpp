#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,people,capacity,c=0;
    cin>>n;
    while(n--)
    {
        cin>>people>>capacity;
        if(capacity-people>=2)
            c++;
    }
    cout<<c<<endl;
    return 0;
}