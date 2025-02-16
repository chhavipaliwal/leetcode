class Solution {
    bool backTrack(vector<int> &vec,set<int> st,int idx,int &sz){
        if(idx==sz) return 1;
        
        if(vec[idx]) return backTrack(vec,st,idx+1,sz);
         

         
         std::set<int>::reverse_iterator rev_it;

        for (rev_it = st.rbegin(); rev_it != st.rend(); rev_it++) {
            int val = *rev_it;
            if(val!=1){
               if(idx + val < sz && !vec[idx+val]){
                   vec[idx] = vec[idx + val] =  val; 
                   st.erase(val);
                   if(backTrack(vec,st,idx+1,sz)) return 1; 
                   st.insert(val);
                   vec[idx] = vec[idx+val] = 0;         
               }
            } else {
                vec[idx] = val;
                st.erase(val);
                if(backTrack(vec,st,idx+1,sz)) return 1;      
                st.insert(val);
                vec[idx] = 0;
            }
        }
        return 0;
        
    }
public:
    vector<int> constructDistancedSequence(int n) {
         set<int> st;
        for(int i =1 ; i <= n ; i++){
            st.insert(i);
        }
        int sz = (n-1)*2 + 1;
        vector<int> vec(sz,0);
        backTrack(vec,st,0,sz);
        return vec;
    }
};