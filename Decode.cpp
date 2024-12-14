#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define endl "\n"
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define vi vector<int>
#define si set<int>
#define vvi vector<vi>
#define vc vector<char>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define mi map<int, int>
#define miv map<int, vector<int>>
#define f(i, n) for (int i = 0; i < n; i++)
#define f1(i, k, n) for (int i = k; i < n; i++)
#define f2(i, k, n) for (int i = k - 1; i >= n; i--)

const int INF = 1e9 + 7;
const int mod = 1e9 + 7;

template<class T>
void inp(vector<T>& a) { for (auto& x : a) cin >> x; }

template<class T>
void print(vector<T>& a) {
    for (auto& x : a) cout << x << " ";
    cout << endl;
}

template<class T>
void print(T x) { cout << x << " "; }

template<class T>
void println(T x) { cout << x << "\n"; }

template<class T>
T maxEle(vector<T>& a) {
    T maxi = LLONG_MIN;
    for (auto x : a)
        if (x > maxi) maxi = x;
    return maxi;
}

template<class T>
T minEle(vector<T>& a) {
    T mini = LLONG_MAX;
    for (auto x : a)
        if (x < mini) mini = x;
    return mini;
}

int fact[1000001];

const int N = 10000000;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

bool isprime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int power(int a, int b) {
    if (b == 0) {
        return 1;
    } else if (b < 0) {
        a = 1 / a;
        b = -b;
    }

    int result = 1;
    while (b > 0) {
        if (b & 1) {
            result *= a;
            result %= mod; // Take modulo here to avoid overflow
        }
        a *= a;
        a %= mod; // Take modulo here to avoid overflow
        b >>= 1;
    }
    return result;
}

int inv(int n) {
    return power(n, mod - 2);
}

int nCr(int n, int r) {
    if (r < 0 || r > n)
        return 0; // Invalid input, return 0
    return fact[n] * inv(fact[r]) % mod * inv(fact[n - r]) % mod;
}

vector<int> tobinary(int x) {
    vector<int> binary;
    while (x > 0) {
        binary.push_back(x % 2);
        x /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

int todecimal(vector<int> binary) {
    int decimal = 0;
    for (int i = 0; i < binary.size(); i++) {
        decimal += binary[i] * (1LL << (binary.size() - i - 1));
    }
    return decimal;
}

bool isBitSet(int num, int i) {
    return (num & (1LL << i)) != 0;
}

void factorial() {
    fact[0] = 1;
    for (int i = 1; i <= 1000000; i++)
        fact[i] = (1LL * fact[i - 1] * i) % mod;
}

int modularAddition(int a, int b, int mod) {
    // Add a and b, then take modulo mod
    int result = (a % mod + b % mod) % mod;
    return (result + mod) % mod; // Ensure result is positive
}

int modularMultiplication(int a, int b, int mod) {
    // Multiply a and b, then take modulo mod
    return ((a % mod) * (b % mod)) % mod;
}

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

bool isPerfect(int n) {
    int a = (int)sqrt(n);
    return (n == a * a);
}

void precompute() {
}



void solve() {
    string s;
    cin >> s;
    int ans = 1;
    int n = s.length();
    vi v1(n + 1), v2(2 * n + 2);
    
    f(i, n) {
        v1[i + 1] = v1[i];
        if (s[i] - '0')
            v1[i + 1] += 1;
        else
            v1[i + 1] -= 1;
    }

    f1(j, 1, n + 1) {
        int ind1 = v1[j - 1] + n;
        v2[ind1] += j;
        //println(v2[ind]);
        int ind2 = v1[j] + n;
        //ans+=(long long)v2[ind2] * (n - j + 1)%mod;
        ans = modularAddition(ans,(long long)v2[ind2] * (n - j + 1),mod);
    }
    ans--;
    cout << ans << endl;
}



/*
4
0000
01010101
1100111001
11000000111


*/

signed main() {
    FAST;
    precompute();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}