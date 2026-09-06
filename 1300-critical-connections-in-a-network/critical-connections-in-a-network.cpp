class Solution {
public:
    vector<int> dt;
    vector<int> low;
    int time=0;
    vector<vector<int>> answer;
    void dfs(int u,int parU,vector<vector<int>>& connections){
        dt[u]=low[u]=++time;
        for(auto &v:connections[u]){
            if(dt[v]==-1){
                dfs(v,u,connections);
                low[u]=min(low[u],low[v]);
                if(low[v] > dt[u]){
                    answer.push_back({u,v});
                }
            }else if(v!=parU){
                low[u]=min(low[u],dt[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        dt.resize(n,-1);
        low.resize(n);
        vector<vector<int>> adj(n);
        for(auto &e:connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n;i++){
            if(dt[i]==-1){
                dfs(i,-1,adj);
            }
        }
        return answer;
    }
};