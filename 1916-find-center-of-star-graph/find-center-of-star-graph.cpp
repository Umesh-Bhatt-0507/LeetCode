class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> degree;
        for(auto &edge:edges){
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        for(auto &[u,v]:degree){
            if(v==edges.size()){
                return u;
            }
        }
        return -1;
        


        // unordered_map<int,vector<int>> adj;
        // for(auto &edge:edges){
        //     int u=edge[0];
        //     int v=edge[1];
        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }
        // for(auto &[u,v]:adj){
        //     if(v.size()==edges.size()){
        //         return u;
        //     }          
        // }
        // return -1;
    }
};