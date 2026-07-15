class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(auto &[u,v]:adj){
            if(v.size()==edges.size()){
                return u;
            }          
        }
        // for(auto v:adj){
        //     cout<<adj[v].size()<<endl;
        // }
        return -1;
    }
};