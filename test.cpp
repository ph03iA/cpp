#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int number;
        cin >> number;
        int n = number;
        int x = floor(log10(abs(n))) + 1;

        while (n >= 100) {
            n /= 10;
        }

        if(x==3){
            if(number%100 >= 2 && n == 10) {cout << "YES" << endl;}
            else cout << "NO" << endl;
        }

        else if(x==4){

            int tensPlace = (number / 10) % 10;
            if((number%100>=2) && (n == 10) && (tensPlace!=0)) {cout << "YES" << endl;}
            else cout << "NO" << endl;
        }

        else if(x==5){
            int hunPlace = (number / 100) % 10;
            if((number%100>=2)&&(n == 10) && (hunPlace!=0)) {cout << "YES" << endl;}
            else cout << "NO" << endl;
        }
    }

    return 0;
}
