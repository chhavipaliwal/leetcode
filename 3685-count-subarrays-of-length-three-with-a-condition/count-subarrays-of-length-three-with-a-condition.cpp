class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        int cnt=0;
        while(j<n){
            if(j-i+1==3){
                if(nums[i]+nums[j]==(nums[i+1]/2) and (nums[i+1]%2==0))cnt++;
                i++;
            }
            j++;
        }
        return cnt;
    }
};