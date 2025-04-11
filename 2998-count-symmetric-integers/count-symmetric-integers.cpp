class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for(int i=low; i<=high; i++) {
            string str = to_string(i);
            if(str.size() % 2 == 0) {
                int temp1 = 0, temp2 = 0;
                for(int x=0; x<(str.size()/2); x++) {
                    temp1 += str[x];
                    temp2 += str[str.size()-1-x];
                }
                res += (temp1 == temp2) ? 1 : 0;
            }
        }
        return res;
    }
};