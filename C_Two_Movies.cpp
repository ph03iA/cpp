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
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
void adjustForPositive(int &X, int &Y, int &H)
{
    int positiveAdjustment = min(Y - X, H);
    X += positiveAdjustment;
    H -= positiveAdjustment;

    int halfRemainingP = H / 2;
    X += halfRemainingP;
    Y += H - halfRemainingP;

    if (X > Y)
    {
        swap(X, Y);
    }
}

void adjustForNegative(int &X, int &Y, int &J)
{
    int negativeAdjustment = max(X - Y, J);
    Y += negativeAdjustment;
    J -= negativeAdjustment;

    int halfRemainingN = J / 2;
    X += halfRemainingN;
    Y += J - halfRemainingN;
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

        vector<int> a(n), b(n);

        fo(i, n)
        {
            cin >> a[i];
        }

        fo(i, n)
        {
            cin >> b[i];
        }

        int H = 0, J = 0;
        int X = 0, Y = 0;

        fo(i, n)
        {
            if (a[i] == b[i])
            {
                if (a[i] == -1)
                {
                    J--;
                }
                else if (a[i] == 1)
                {
                    H++;
                }
            }
            else
            {
                X += max(a[i], 0);
                Y += max(b[i], 0);
            }
        }

        if (X > Y)
        {
            swap(X, Y);
        }

        adjustForPositive(X, Y, H);

        adjustForNegative(X, Y, J);

        cout << min(X, Y) << '\n';
    }
    return 0;
}