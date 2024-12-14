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
                       
bool isSquare(int n) {
    int r = sqrt(n);
    return r * r == n;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        
        if (!isSquare(n)) {
            cout << "No" << endl;
            continue;
        }
        
        int r = sqrt(n);
        bool isBeautiful = true;
        
        
        fo(j, r) {
            if (s[j] != '1' || s[n-r+j] != '1') {
                isBeautiful = false;
                break;
            }
        }
        
       
        for (int i = 1; i < r-1 && isBeautiful; i++) {
            if (s[i*r] != '1' || s[(i+1)*r - 1] != '1') {
                isBeautiful = false;
                break;
            }
            for (int j = 1; j < r-1; j++) {
                if (s[i*r + j] != '0') {
                    isBeautiful = false;
                    break;
                }
            }
        }
        
        if (isBeautiful) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
