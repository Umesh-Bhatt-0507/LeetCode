class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int low=0;
        int high=0;
        int ans=INT_MIN;
        unordered_map<int,int> mp;
        while(high<nums.size()){
            mp[nums[high]]++;
            if(mp[nums[high]] >k){
                while(mp[nums[high]] >k){
                    mp[nums[low]]--;
                    low++;
                }
            }
            high++;
            ans=max(ans,high-low);
        }
        return ans;
    }
};