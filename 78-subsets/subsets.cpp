class Solution {
public:
    void add(vector<int>& nums,int i,vector<vector<int>> &answer,vector<int> part){
        if(i==nums.size()){
            answer.push_back(part);
            return;
        }
        part.push_back(nums[i]);
        add(nums,i+1,answer,part);
        part.pop_back();
        add(nums,i+1,answer,part);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> part;
        add(nums,0,answer,part);
        return answer;
    }
};