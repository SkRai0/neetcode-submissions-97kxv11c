class Solution {
    void dfs(vector<int> graph[], int node, vector<bool>& vis){
        vis[node] = true;
        for(auto& it: graph[node]){
            if(vis[it] == false){
                dfs(graph, it, vis);
            }
        }
        return;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        int ans = 0;
        vector<bool> vis(n, false);
        for(int i=0;i<n;i++){
            if(vis[i] == false){
                dfs(graph, i, vis);
                ans++;
            }
        }

        return ans;
    }
};
