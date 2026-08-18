class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int bv=nums[0];
        int wv=nums[0];
        int s=nums[0];
        int ans=nums[0];
        int minAns=nums[0];
        for(int i=1;i<nums.size();i++){
            s+=nums[i];
            int a=nums[i];
            int b=nums[i]+bv;
            int c=nums[i]+wv;
            bv=max(a,b);
            ans=max(ans,bv);
            wv=min(c,a);
            minAns=min(minAns,wv);
        }
        if(ans<0){
            return ans;
        }
        return max(ans,s-minAns);
    }
};