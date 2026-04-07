/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool custComp(pair<int,int> p1, pair<int,int> p2){
        return p1.first==p2.first?p2.second>p1.second:p2.first>p1.first;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int,int>> vp;
        for(int i=0;i<intervals.size();i++){
            vp.push_back({intervals[i].start, 1});
            vp.push_back({intervals[i].end, -1});
        }

        sort(vp.begin(), vp.end(), custComp);

        int maxi = 0, cnt = 0;
        for(int i=0;i<vp.size();i++){
            cnt+=vp[i].second;
            maxi=max(maxi, cnt);
        }

        return maxi;
    }
};
