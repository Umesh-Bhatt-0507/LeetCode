class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        unordered_set<int> s;
        for(int i=0;i<=nums.size()-k;i++){
            for(int j=i;j<k+i;j++){
                if(!s.count(nums[j])){
                    mp[nums[j]]++;
                }
                s.insert(nums[j]);
            }
            s.clear();
        }
        int m=-1;
        for(auto &v: mp){
            if(v.second==1){
                m=max(m,v.first);
            }
        }
        return m;
    }
};