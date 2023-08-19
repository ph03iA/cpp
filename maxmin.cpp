#include <iostream>
#include <limits.h>
using namespace std;

int getMin(int num[], int n)
{
    int mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (num[i] < mini)
        {
            mini = num[i];
        }
    }
    return mini;
}

int getMax(int num[], int n)
{
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (num[i] > maxi)
        {
            maxi = num[i];
        }
    }
    return maxi;
}

int main()
{
    int num[100];
    int size;
    cin>>size;

    for (int i = 0; i < size; i++)
    {

        cin >> num[i];
    }
    cout << "the maximum value is: "<<getMax(num, size)<<endl;
    cout << "the minimum value is: "<<getMin(num, size)<<endl;

    return 0;
}