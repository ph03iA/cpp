#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string a, b;
    int groups = 1;

    cin >> a;

    for (int i = 1; i < n; ++i)
    {
        cin >> b;
        if (b != a)
        {
            groups++;
            a = b;
        }
    }

    cout << groups << endl;

    return 0;
}


