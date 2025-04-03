class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        
        long long max_value = 0;
        int max_i = nums[0];
        int max_diff = INT_MIN;
        
        for (int j = 1; j < n - 1; ++j) {
            max_diff = max(max_diff, max_i - nums[j]);
            max_value = max(max_value, (long long)max_diff * nums[j + 1]);
            max_i = max(max_i, nums[j]);
        }
        
        return max_value;
    }
};