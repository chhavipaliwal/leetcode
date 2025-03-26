template<typename T1, typename T2> bool cmax(T1 &x, const T2 &y) { if (x < y) { x = y; return 1; } return 0; }
class Solution {
public:
    bool check(vector<pair<int, int>> arr){
        sort(arr.begin(),arr.end());
        int prev = -1;
        int cnt = 0;

        for(int i=0; i<arr.size(); i++){
            int l = arr[i].first;
            int r = arr[i].second;
            if(l>=prev){
                cnt++;
                prev = r;
            }
            else cmax(prev, r);
        }
        return cnt>=3 ? true: false;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rect) {
        int size = rect.size();
        vector<pair<int, int>> r1, r2;

        for(auto it: rect){
            r1.push_back({it[0], it[2]});
            r2.push_back({it[1], it[3]});
        }

        return check(r1) || check(r2);
    }
};