class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini = nums[0];     // minimum element seen so far
        int ans = 0;            // maximum difference
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            mini = min(mini, nums[i]);         // update minimum
            ans = max(ans, nums[i] - mini);    // update max difference
        }

        return ans > 0 ? ans : -1; // if no valid pair found, return -1
    }
};