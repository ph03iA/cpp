class Solution { 
public: 
    long long findScore(const vector<int>& nums) { 
        int n = nums.size(); 
        long long score = 0; 
        
        for (unsigned int i = 0; i < n; i += 2) { 
            long long odd = 0, even = 0; 
            
            for (int val = nums[i], next; i + 1 < n && nums[i] > (next = nums[i + 1]); i++, val = next) {

                if (i & 1) {
                    odd += val;
                } else {
                    even += val;
                }
            } 
            
            if (i & 1) {
                score += odd + nums[i];
            } else {
                score += even + nums[i];
            }
        } 
        
        return score; 
    } 
};