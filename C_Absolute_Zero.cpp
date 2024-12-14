#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#define gc getchar_unlocked
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
#define read(type) readInt<type>() // Fast read
                       
using namespace std;
                       
int gcd(int a, int b)
{
    if(b == 0){
       return a;
    }
    return gcd(b, a%b);
}
                       
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        bool par = true;
        for (int i = 1; i < n; ++i)
        {
            if ((a[i] % 2) != (a[0] % 2))
            {
                par = false;
                break;
            }
        }

        if (!par)
        {
            cout << "-1\n";
            continue;
        }

        vector<int> operations;
        while (true)
        {
            int mn = *min_element(a.begin(), a.end());
            int mx = *max_element(a.begin(), a.end());
            if (mx == 0)
                break;

            int low = 0, high = mx, bx = mx, bm = mx;

            while (low <= high)
            {
                int mid = low + (high - low) / 2;

                int cm = 0;
                for (int x : a)
                {
                    cm = max(cm, abs(x - mid));
                }

                if (cm < bm)
                {
                    bm = cm;
                    bx = mid;
                }

                if (mid == 0)
                {
                    break;
                }

                if (cm == mx)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

            operations.push_back(bx);

            for (int &x : a)
            {
                x = abs(x - bx);
            }

            if (operations.size() >= 40)
                break;
        }

        if (*max_element(a.begin(), a.end()) != 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << operations.size() << endl;
            for (int x : operations)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}