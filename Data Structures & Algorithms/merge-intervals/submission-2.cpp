class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        int st=intervals[0][0],en=intervals[0][1];
        for(int i=1;i<n;i++){
            if(en>=intervals[i][0]){
                if(en<intervals[i][1])
                en = intervals[i][1];
            }
            else{
                ans.push_back({st, en});
                st=intervals[i][0];
                en=intervals[i][1];
            }
        }
        ans.push_back({st, en});
        return ans;
    }
};
