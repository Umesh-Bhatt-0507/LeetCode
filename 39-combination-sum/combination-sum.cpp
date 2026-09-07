class Solution {
public:
    vector<vector<int>> answer;
    void helper(int idx,vector<int> &candidates,int remaining,vector<int> &temp){
        if(remaining==0){
            answer.push_back(temp);
            return;
        }
        if(remaining<0 || idx>candidates.size()-1){
            return;
        }
        temp.push_back(candidates[idx]);
        helper(idx,candidates,remaining-candidates[idx],temp);
        temp.pop_back();
        helper(idx+1,candidates,remaining,temp);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        helper(0,candidates,target,temp);
        return answer;
    }
};