#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int minimumRightShifts(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        for (int i = 0; i < n; ++i)
        {
            bool is_sorted = true;
            for (int j = 0; j < n; ++j)
            {
                if (sorted_nums[j] != nums[(j + i) % n])
                {
                    is_sorted = false;
                    break;
                }
            }
            if (is_sorted)
            {
                return n - i;
            }
        }
    }
            };