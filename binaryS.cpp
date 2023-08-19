#include <iostream>
using namespace std;

int firstOcc(int nums[], int n, int key)
{

    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (nums[mid] < key)
        {
            s = mid + 1;
        }
        else if (nums[mid] > key)
        {
            s = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int lastOcc(int nums[], int n, int key)
{

    int s = 0, e = n - 1;

    int ans = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        
        if (nums[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (nums[mid] < key)
        {
            s = mid + 1;
        }
        else if (nums[mid] > key)
        {
            s = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int arr[6] = {2, 4, 5, 3, 3, 5};
    
    cout << "First occurance of 3 is at index: " << firstOcc(arr, 6, 3) << endl;
    cout << "Last occurance of 3 is at index: " << lastOcc(arr, 6, 3) << endl;

    return 0;
}