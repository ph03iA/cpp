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

bool isStrongPassword(string &password)
{
    int n = password.size();
    string digits, letters;

    for (char c : password)
    {
        if (isdigit(c))
        {
            digits += c;
        }
        else
        {
            letters += c;
        }
    }

    if (!is_sorted(digits.begin(), digits.end()))
    {
        return false;
    }

    if (!is_sorted(letters.begin(), letters.end()))
    {
        return false;
    }

    bool foundLetter = false;
    for (char c : password)
    {
        if (isalpha(c))
        {
            foundLetter = true;
        }
        else if (isdigit(c) && foundLetter)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string password;
        cin >> n >> password;
        if (isStrongPassword(password))
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
