class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
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
                for(auto &v:graph[u]){
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