class Solution {
public:
    vector<vector<int>> answer;
    void dfs(vector<vector<int>>& graph,int u,vector<int> store){
        store.push_back(u);
        if(u==(graph.size()-1)){
            answer.push_back(store);
            return;
        }
        for(auto &v:graph[u]){
            dfs(graph,v,store);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph,0,{});
        return answer;
    }
};