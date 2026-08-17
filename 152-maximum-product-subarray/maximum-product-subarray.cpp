class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int bv=nums[0];
        int wv=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int a=nums[i]*bv;
            int b=nums[i]*wv;
            int c=nums[i];
            bv=max(a,max(b,c));
            wv=min(a,min(b,c));
            ans=max(ans,bv);
        }
        return ans;
    }
};