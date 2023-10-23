#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    const int N = 110;
    double sum;
    double p[N];
    

    for (int i = 0; i < n; i++)
    {
        int p[i];
        cin >> p[i];

        sum += p[i];
        
    }
    cout << sum / n << endl;
}