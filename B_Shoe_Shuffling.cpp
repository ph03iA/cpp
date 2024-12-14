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
        cin >> n;
        vector<int> s(n);
        map<int, int> m;
        fo(i, n) {
            cin >> s[i];
            m[s[i]]++;
        }
        bool foundUnique = false;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second == 1) {
                cout << "-1" << endl;
                foundUnique = true;
                break;
            }
        }
        if (foundUnique) {
            continue;
        }
        vector<int> p(n);
        fo(i, n) {
            int a = i + 1;
            while (i + 1 < n && s[i] == s[i + 1]) {
                p[i] = i + 2;
                i++;
            }
            p[i] = a;
        }
        fo(i, n) {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
