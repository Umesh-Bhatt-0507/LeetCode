class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // unordered_map<int,int> store;
        // for(int i=0;i<nums.size();i++){
        //     if(store.count(nums[i]) && abs(i-store[nums[i]])<=k){
        //         return true;
        //     }
        //     store[nums[i]]=i;
        // }
        // return false;

        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            if(s.size() > k){
                s.erase(nums[i-k-1]);
            }
            if(s.count(nums[i])){
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};