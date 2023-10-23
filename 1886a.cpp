#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        bool found = false;

        for (int x = 1; x < n; x++)
        {
            for (int y = x + 1; y < n; y++)
            {
                int z = n - x - y;
                if (z > 0 && z != x && z != y && (x % 3 != 0) && (y % 3 != 0) && (z % 3 != 0))
                {
                    found = true;
                    cout << "YES "<< endl << x << " " << y << " " << z << endl;
                    break;
                }
            }

            if (found)
                break;
        }

        if (!found)
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
