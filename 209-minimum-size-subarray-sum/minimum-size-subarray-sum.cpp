class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int ans=INT_MAX;
        int sum=0;
        for(int h=0;h<nums.size();h++){
            sum+=nums[h];
            while(sum >= target){
                ans=min(ans,h-l+1);
                sum-=nums[l];
                l++;
            }
        }
        if(ans==INT_MAX){
            return 0;
        }
        return ans;
    }
};