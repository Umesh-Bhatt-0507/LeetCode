class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);
        for(auto &edge:dislikes){
            adj[edge[0]-1].push_back(edge[1]-1);
            adj[edge[1]-1].push_back(edge[0]-1);
        }
        vector<int> color(n,-1);
        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(color[i]!=-1){
                continue;
            }
            q.push(i);
            color[i]=0;
            while(!q.empty()){
                int u=q.front();
                int c=color[u];
                q.pop();
                for(auto &v:adj[u]){
                    if(color[v]!=-1){
                        if(color[v]==color[u]){
                            return false;
                        }
                    }else{
                        if(c==1){
                            color[v]=0;
                        }else{
                            color[v]=1;
                        }
                        q.push(v);
                    }
                }
            }
        }
        return true;
    }
};