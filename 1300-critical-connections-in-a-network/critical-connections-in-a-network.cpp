class Solution {
public:
    int time;
    vector<int> dt,low;
    void dfs(int u,int parU,vector<vector<int>> &cc,vector<vector<int>> &graph){
        dt[u]=low[u]=++time;
        for(auto &v:graph[u]){
            if(dt[v]==-1){
                dfs(v,u,cc,graph);
                low[u]=min(low[u],low[v]);
                if(low[v] > dt[u]){
                    cc.push_back({u,v});
                }
            }else if(v!=parU){
                low[u]=min(low[u],dt[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
        vector<vector<int>> bridges;
        vector<vector<int>> graph(n);
        for(auto u:connections){
            graph[u[0]].push_back(u[1]);
            graph[u[1]].push_back(u[0]);
        }
        
        time=0;
        dt.resize(n,-1);
        low.resize(n);
        for(int i=0;i<n;i++){
            if(dt[i]==-1){
                dfs(i,-1,bridges,graph);
            }
        }
        return bridges;
    }
};