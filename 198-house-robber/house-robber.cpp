class Solution {
public:
    int ans(vector<int> &nums,int idx,vector<int> &dp){
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int left=nums[idx]+ ans(nums,idx+2,dp);
        int right=ans(nums,idx+1,dp);
        return dp[idx]=max(left,right);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return ans(nums,0,dp);
    }
};