class Solution {
public:
    int helper(int st,int end, vector<int> &nums){
        int n=nums.size();

        int prev1=nums[st];
        int prev2=max(nums[st+1],nums[st]);
        int result=prev2;

        for(int i=st+2,j=2;i<=end;i++,j++){
            result=max(prev1+nums[i],prev2);

            prev1=prev2;
            prev2=result;
        }
        return result;
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