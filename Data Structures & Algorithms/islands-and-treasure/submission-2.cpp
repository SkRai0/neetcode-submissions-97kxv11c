class Solution {
    int INF = 2147483647;
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return;
        int m = grid[0].size();
        queue<pair<int, int>> q;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == INF) {
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};