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
        string s;
        cin >> n >> s;

        
        vector<int> count(26, 0);

        
        for (char c : s) {
            count[c - 'a']++;
        }

        string result = "";
        bool done = false;

        while (!done) {
            done = true;

           
            for (int i = 0; i < 26; i++) {
                if (count[i] > 0) {
                    result += (char)('a' + i);
                    count[i]--;
                    done = false;  
                }
            }
        }

        cout << result << endl;
    }
    return 0;
}