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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);



        set<char> distinctChars;

        //set me daal diya qki set me reapeating chars ek hi baar aate 

        fo(i, n)
        {
            distinctChars.insert(s[i]);
            prefix[i] = distinctChars.size(); //size de
        }

        distinctChars.clear();

        //set me daal diya qki set me reapeating chars ek hi baar aate 

        for (int i = n - 1; i >= 0; --i)
        {
            distinctChars.insert(s[i]);
            suffix[i] = distinctChars.size();
        }

        int ans = 0;
        fo(i, n-1)
        {
            ans = max(ans, prefix[i] + suffix[i + 1]);
        }

        cout << ans << endl;
    }

    return 0;
}