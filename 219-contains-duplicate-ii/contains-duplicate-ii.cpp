class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // map<int,int> store;
        // for(int i=0;i<nums.size();i++){
        //     if(store.count(nums[i]) && abs(i-store[nums[i]])<=k){
        //         return true;
        //     }
        //     store[nums[i]]=i;
        // }
        // return false;

        unordered_set<int> store;
        for(int i=0;i<nums.size();i++){
            if(i>k){
                store.erase(nums[i-k-1]);
            }
            if(store.count(nums[i])){
                return true;
            }
            store.insert(nums[i]);
        }
        return false;
    }
};