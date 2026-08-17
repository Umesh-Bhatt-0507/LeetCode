class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bv=nums[0];
        int ans=bv;
        for(int i=1;i<nums.size();i++){
            bv=max(nums[i], nums[i]+bv);
            ans=max(ans,bv);
        }
        return ans;
    }
};