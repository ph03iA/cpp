#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#define ll long long
#define ms(a) memset(a,0,sizeof(a))
#define pi acos(-1.0)
#define INF 0x3f3f3f3f
const double E=exp(1);
const int maxn=1e6+10;
using namespace std;
char c[maxn];
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin>>c;
	int l=strlen(c);
	int temp=0;
	for(int i=0;i<l;i++)
	{
		if(c[i]=='H'||c[i]=='Q'||c[i]=='9')
			temp++;
	}
	if(temp)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}