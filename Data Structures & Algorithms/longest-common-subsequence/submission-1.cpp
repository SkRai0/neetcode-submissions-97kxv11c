class Solution {
    vector<vector<int>> dp;
    int helper(string t, string s, int n, int m){
        if(n<0 || m<0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(t[n] == s[m]){
            return dp[n][m] = 1+helper(t,s,n-1,m-1);
        }
        return dp[n][m] = max(helper(t,s,n-1,m), helper(t,s,n,m-1));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        //TC: O(N)
        dp.resize(text1.length(), vector<int>(text2.length(), -1));
        return helper(text1, text2, text1.length()-1, text2.length()-1);
    }
};
