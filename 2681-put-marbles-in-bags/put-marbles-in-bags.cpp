class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(k == 1 || n == k) return 0LL;
        vector<long long>v; 
        for(int i = 0; i < n-1; i++){
            v.push_back(weights[i]+weights[i+1]);
        }
        sort(v.begin(), v.end());
        long long mini = accumulate(v.begin(), v.begin()+(k-1), 0LL);
        long long maxi = accumulate(v.end() - (k-1), v.end(), 0LL);
        return (maxi-mini);
    }
};