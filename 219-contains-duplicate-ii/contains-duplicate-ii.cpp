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
        int r=0;
        int l=0;
        for(int i=0;i<nums.size();i++){
            if(r-l > k){
                s.erase(nums[i-k-1]);
                l++;
            }
            if(s.count(nums[i])){
                return true;
            }
            s.insert(nums[i]);
            r++;
        }
        return false;
    }
};