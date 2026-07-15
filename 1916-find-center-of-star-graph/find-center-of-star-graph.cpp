class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            if(adj[u].size()==edges.size()){
                return u;
            }
            adj[v].push_back(u);
            if(adj[v].size()==edges.size()){
                return v;
            }
        }
        // for(auto &[u,v]:adj){
        //     if(v.size()==edges.size()){
        //         return u;
        //     }          
        // }
        return -1;
    }
};