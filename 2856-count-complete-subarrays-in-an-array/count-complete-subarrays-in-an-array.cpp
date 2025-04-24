class Solution {
public:
    long long countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size(); 
        unordered_set<int> all(nums.begin(), nums.end());
        int k = all.size(); 
        unordered_map<int,int> mp;
        long long ans = 0;
        int l = 0; 
        for (int r = 0; r < n; ++r) { 
            mp[nums[r]]++; 
            while((int)mp.size() == k){ 
                ans += (n - r); 
                if(--mp[nums[l]] == 0) mp.erase(nums[l]);  
                l++;
            }
        } 
        return ans;
    }
};