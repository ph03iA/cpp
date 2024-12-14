#include <iostream>
using namespace std;

int large[5] = {5, 6, 7, 8, 9};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        string s = to_string(n);
        int sz = s.size();

        string small = "01234", large = "56789";
        if (s.find(small) != string::npos && s.find(large) != string::npos)
        {
            cout << "NO" << endl;
            break;
        }

        int hZ = 0;
        int sum = 0, bt = 5 + 6 + 7 + 8 + 9;

        for (int i = 0; i < sz - 1; i++)
        {
            sum += (s[i] - '0');
            if (s[i] == '0')
                hZ = 1;
        }

        if (s[sz - 1] == '9' || sum == bt || s[0] != '1' || sz % 10 == 0 || hZ)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}