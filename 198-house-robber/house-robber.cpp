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
        if(n<2){
            return nums[0];
        }
        vector<int> dp(n,-1);
        // return ans(nums,0,dp);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
};