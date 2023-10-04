#include<bits/stdc++.h>
using namespace std;
                    
int main(){
    int n;
    cin >> n;

    int x = 0, p = 0;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> b >> a;

        p += (a - b);
        x = max(x, p);
    }

    cout << x << endl;
    return 0;	    
}