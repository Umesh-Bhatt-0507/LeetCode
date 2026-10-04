class Solution {
public:
    int helper(int st,int end, vector<int> &nums){
        if(end-st ==0){
            return nums[st];
        }
        if(end-st ==1){
            return max(nums[st],nums[st+1]);
        }
        vector<int> dp(end-st+1);
        dp[0]=nums[st];
        dp[1]=max(nums[st+1],nums[st]);
        for(int i=2;i+st<=end;i++){
            dp[i]=max(dp[i-2]+nums[i+st],dp[i-1]);
        }
        return dp[end-st];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        int ans1=helper(0,n-2,nums);
        int ans2=helper(1,n-1,nums);
        return max(ans1,ans2);
    }
};