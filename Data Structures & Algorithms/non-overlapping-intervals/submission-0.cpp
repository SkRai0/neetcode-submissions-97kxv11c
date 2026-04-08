class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int currEnd = intervals[0][1];
        int ans = 0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] >= currEnd){
                currEnd = intervals[i][1];
            }
            else{
                ans++;
                currEnd = min(currEnd, intervals[i][1]);
            }
        }
        return ans;
    }
};
