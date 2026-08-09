class Solution {
public:
    void dfs(int curr,int u,vector<bool> &visited,vector<vector<int>> &answer,vector<vector<int>> &adj){
        visited[u]=true;
        for(auto &v:adj[u]){
            if(!visited[v]){
                answer[v].push_back(curr);
                dfs(curr,v,visited,answer,adj);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }
        vector<vector<int>> answer(n);
        for(int i=0;i<n;i++){
            vector<bool> visited(n,false);
            dfs(i,i,visited,answer,adj);
        }
        return answer;
    }
};