class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        vector<int> dp1(cost.size(), -1);
        return min(dfs(cost, 0, dp), dfs(cost, 1, dp1));
    }

    int dfs(vector<int>& cost, int i, vector<int>& dp) {
        if (i >= cost.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        dp[i] = cost[i] + min(dfs(cost, i + 1, dp), dfs(cost, i + 2, dp));
        return dp[i];
    }
};