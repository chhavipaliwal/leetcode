class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>freq;
        int n=nums.size();
        int d=-1;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            if(freq[nums[i]]>n/2){
                d=nums[i];
            }
        }
        int f=0;
        for(int i=0;i<n;i++){
            if(nums[i]==d){
                f++;
                freq[nums[i]]--;
                if(f>(i+1)/2&&freq[nums[i]]>(n-i-1)/2){
                    return i;
                }
            }
        }
        return -1;
    }
};