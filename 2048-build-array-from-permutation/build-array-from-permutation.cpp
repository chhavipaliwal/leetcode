class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int oldVal = nums[i];
            int newVal = nums[nums[i]] & 1023; 
            
            nums[i] = oldVal | (newVal << 10);
        }

        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] >> 10;
           
        }

        return nums;
    }
};