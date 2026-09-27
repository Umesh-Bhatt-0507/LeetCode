class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i]) && abs(i-m[nums[i]])<=k){
                return true;
            }
            m[nums[i]]=i;
        }
        return false;

        // unordered_set<int> s;
        // int l=0;
        // int r=0;
        // for(int i=0;i<nums.size();i++){
        //     if(r-l > k){
        //         s.erase(nums[r-k-1]);
        //         l++;
        //     }
        //     if(s.count(nums[i])){
        //         return true;
        //     }else{
        //         s.insert(nums[i]);
        //         r++;
        //     }
        // }
        // return false;
    }
};