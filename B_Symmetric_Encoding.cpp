#include <bits/stdc++.h>
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

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

map<char, char> generateMapping(const string &s)
{
    set<char> uniqueChars(s.begin(), s.end());
    vector<char> sortedChars(uniqueChars.begin(), uniqueChars.end());
    sort(sortedChars.begin(), sortedChars.end());
    vector<char> reversedChars(sortedChars.rbegin(), sortedChars.rend());

    map<char, char> charMapping;
    for (size_t i = 0; i < sortedChars.size(); ++i)
    {
        charMapping[sortedChars[i]] = reversedChars[i];
    }
    return charMapping;
}

string applyMapping(const string &s, const map<char, char> &charMapping)
{
    string result;
    for (char c : s)
    {
        result += charMapping.at(c);
    }
    return result;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        map<char, char> charMapping = generateMapping(s);
        string ans = applyMapping(s, charMapping);

        cout << ans << endl;
    }
    return 0;
}
