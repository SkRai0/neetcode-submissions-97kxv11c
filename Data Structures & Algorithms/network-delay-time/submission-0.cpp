class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time(n+1, INT_MAX);
        time[k] = 0;
        vector<pair<int,int>> dg[n+1];
        for(int i=0;i<times.size();i++){
            dg[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while(!pq.empty()){
            pair<int,int> top = pq.top();
            pq.pop();
            int node = top.second;
            int wt = top.first;

            for(auto& it: dg[node]){
                int newWt = wt+it.second;
                if(newWt<time[it.first]){
                    time[it.first] = newWt;
                    pq.push({newWt, it.first});
                }
                
            }
        }

        int maxT = INT_MIN;
        for(int i=1;i<=n;i++){
            maxT = max(maxT, time[i]);
        }

        return maxT==INT_MAX?-1:maxT;
    }
};
