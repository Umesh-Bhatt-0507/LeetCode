class Solution {
public:
    vector<vector<int>> answer;
    void helper(int idx,int remaining,vector<int>& candidates,vector<int> &path){
        if(remaining==0){
            answer.push_back(path);
            return;
        }
        if(remaining<0 || idx >candidates.size()-1){
            return;
        }
        path.push_back(candidates[idx]);
        helper(idx+1,remaining-candidates[idx],candidates,path);
        path.pop_back();
        int next=idx+1;
        while(next<candidates.size() && candidates[next]==candidates[idx]){
            next++;
        }
        helper(next,remaining,candidates,path);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> path;
        helper(0,target,candidates,path);
        return answer;
    }
};