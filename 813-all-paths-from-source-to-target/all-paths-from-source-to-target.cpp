class Solution {
public:
    vector<vector<int>> answer;
    void dfs(vector<vector<int>>& graph,int u,vector<int> store){
        if(u==(graph.size()-1)){
            store.push_back(u);
            answer.push_back(store);
            return;
        }
        store.push_back(u);
        for(auto &v:graph[u]){
            dfs(graph,v,store);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph,0,{});
        return answer;
    }
};