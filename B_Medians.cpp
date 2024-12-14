#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        if (n == 1 && k == 1)
        {
            cout << 1 << endl;
            cout << 1 << endl;
            continue;
        }
        if (k % 2 == 1)
        {
            if (n == k || k == 1)
            {
                cout << -1 << endl;
                continue;
            }
            cout << 3 << endl;
            cout << 1 << " " << k - 1 << " " << k + 2 << endl;
        }
        else
        {
            cout << "3\n";
            cout << 1 << " " << k << " " << k + 1 << endl;;
        }
    }

    return 0;
}
