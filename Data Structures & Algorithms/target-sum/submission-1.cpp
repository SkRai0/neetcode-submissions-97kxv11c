class Solution {
    int helper(vector<int>& nums, int tar, int n, int i, int sum, vector<vector<int>>& dp, int pad){
        if(i==n){
            if(sum == tar) return 1;
            else return 0;
        }
        if(dp[i][sum+pad] != INT_MIN) return dp[i][sum+pad];
        return dp[i][sum+pad] = (helper(nums,tar,n,i+1,sum+nums[i],dp,pad)+helper(nums,tar,n,i+1,sum-nums[i],dp,pad));
    }
public:
    int findTargetSumWays(vector<int>& nums, int tar) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(n, vector<int>(2*totalSum + 1, INT_MIN));
        return helper(nums, tar, n, 0, 0, dp, totalSum);
    }
};
