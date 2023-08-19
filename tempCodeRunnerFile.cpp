#include <iostream>
using namespace std;
int diff(int year)
{
    int a, b, c, d;
    a = year % 10;
    year /= 10;
    b = year % 10;
    year /= 10;
    c = year % 10;
    year /= 10;
    d = year;
    if (a != b && a != c && a != d && b != c && b != d && c != d)
        return 0;
    else
        return 1;
}

int main(void)
{
    int year, ans;
    cin >> year;
    ans = year + 1;
    while (diff(ans))
    {
        ans++;
    }
    cout << ans << endl;
    return 0;
}