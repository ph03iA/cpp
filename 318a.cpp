#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    long long mid = n / 2;

    if (n % 2 != 0)
    {
        if (k <= mid + 1)
            cout << (k * 2) - 1 << endl;
        else
            cout << (k - (mid + 1)) * 2 << endl;
    }
    else
    {
        if (k <= n / 2)
            cout << (k * 2) - 1 << endl;
        else
            cout << (k - mid) * 2 << endl;
    }
}
