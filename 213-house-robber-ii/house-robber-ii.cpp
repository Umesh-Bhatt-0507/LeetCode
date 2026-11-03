class Solution {
public:
    int helper(vector<int> &nums, int l, int r){
        if(r-l+1 ==1){
            return nums[l];
        }
        int p2=nums[l];
        int p1=max(nums[l+1],p2);
        for(int i=l+2;i<=r;i++){
            int curr=max(nums[i]+p2,p1);
            p2=p1;
            p1=curr;
        }
        return p1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(helper(nums,0,n-2),helper(nums,1,n-1));
    }
};