class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];
        vector<int> indegree(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int fin = 0;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            fin++;
            for(auto& it: graph[top]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return fin == n;
    }
};
