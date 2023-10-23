#include<bits/stdc++.h>
using namespace std;
#define ll long long int
                    
int main(){
    int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll k=1;
		ll sum=1;
		while(1)
		{
			sum+=pow(2,k++);
			if(n%sum==0)
			{
				cout<<n/sum<<endl;
				break;
			}
		}
	}
    return 0;   
}