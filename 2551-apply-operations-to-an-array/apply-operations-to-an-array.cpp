class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Merge adjacent equal numbers
        for (int i = 0; i < n - 1; i++) { 
            if (nums[i] == nums[i + 1]) {
                nums[i] = 2 * nums[i];
                nums[i + 1] = 0;
            }
        }

        // Step 2: Move all zeros to the right (Bubble Move technique)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (nums[j] == 0 && nums[j + 1] != 0) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }

        return nums;
    }
};

