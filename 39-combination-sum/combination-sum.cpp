class Solution {
public:
    void helper(int i,int curr,vector<int>& candidates,vector<int> path,vector<vector<int>> &answer){
        if(curr==0){
            answer.push_back(path);
            return;
        }
        if(curr<0 || i>candidates.size()-1){
            return;
        }
        path.push_back(candidates[i]);
        helper(i,curr-candidates[i],candidates,path,answer);
        path.pop_back();
        helper(i+1,curr,candidates,path,answer);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        vector<vector<int>> answer;
        helper(0,target,candidates,path,answer);
        return answer;
    }
};