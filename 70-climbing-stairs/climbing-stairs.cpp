class Solution {
public:
    int climbStairsMemo(int n,vector<int> &dp){
        if(n<=2) return n;
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=climbStairsMemo(n-1,dp)+climbStairsMemo(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return climbStairsMemo(n,dp);
    }
};