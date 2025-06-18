class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        while(l<n)
        {
            int diff=nums[l+2]-nums[l];
            if(diff>k)
            {
                return {};
            }
            l+=3;
        }
        vector<vector<int>>ans;
        vector<int>temp;
        for(int i=0;i<n;i++)
        {
            temp.push_back(nums[i]);
            if((i+1)%3==0)
            {
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;

    }
};