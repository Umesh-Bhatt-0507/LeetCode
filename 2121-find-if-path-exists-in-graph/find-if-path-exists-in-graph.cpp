class Solution {
public:
    bool dfs(int src,vector<int> &visited,int &destination,vector<vector<int>> &adj){
        visited[src]=true;
        if(src==destination){
            return true;
        }
        for(int v:adj[src]){
            if(!visited[v]){
                if(dfs(v,visited,destination,adj)){
                    return true;
                }
            }
        }
        return false;

    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> visited(n,false);
        vector<vector<int>> adj(n);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(source,visited,destination,adj);

    }
};