class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        int freshOranges = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                }
                else if(grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }

        vector<pair<int,int>> dir = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        int mxTime = 0;
        while(!q.empty()){
            auto it = q.front();
            int row = it.first.first;
            int col = it.first.second;
            int time = it.second;
            q.pop();
            mxTime = max(mxTime, time);

            for(int i=0;i<4;i++){
                int nwRow = row+dir[i].first;
                int nwCol = col+dir[i].second;

                if(nwRow>=0 && nwCol>=0 && nwRow<n && nwCol<m && grid[nwRow][nwCol] == 1){
                    q.push({{nwRow, nwCol}, time+1});
                    grid[nwRow][nwCol] = 2;
                    freshOranges--;
                }
            }
        }
        
        return freshOranges==0?mxTime:-1;
    }
};
