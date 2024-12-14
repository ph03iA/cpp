#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        set<int> bArr;
        multiset<int> req;

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i)
        {
            cin >> b[i];
            bArr.insert(b[i]);
            if (a[i] != b[i])
            {
                req.insert(b[i]);
            }
        }

        int m;
        cin >> m;
        bool last_check = false;
        for (int i = 0; i < m; ++i)
        {
            int x;
            cin >> x;
            if (req.find(x) != req.end())
            {
                req.erase(req.find(x));
            }
            if (i == m - 1 && (req.find(x) != req.end() || bArr.count(x)))
            {
                last_check = true;
            }
        }

        if (last_check && req.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
