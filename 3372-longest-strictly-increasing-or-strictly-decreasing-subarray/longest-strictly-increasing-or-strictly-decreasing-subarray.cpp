class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxx=1;
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] >= nums[i]){
                count=0;
            }
            count++;
            maxx=max(count,maxx);
        }
        count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] <= nums[i]){
                count=0;
            }
            count++;
            maxx=max(count,maxx);
        }
        return maxx;
    }
};