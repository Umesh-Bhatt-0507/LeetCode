class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }  
        vector<vector<int>> adj(n);
        vector<int> degree(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q.push(i);

            }
        }
        while(n>2){
            int size=q.size();
            n-= size;
            while(size--){
                int u=q.front();
                q.pop();
                for(auto &v:adj[u]){
                    degree[v]--;
                    if(degree[v]==1){
                        q.push(v);
                    }
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};


// class Solution {
// public:
//     int bfs(int src,vector<bool> &visited,vector<vector<int>> adj){
//         int height=0;
//         queue<int> q;
//         q.push(src);
//         visited[src]=true;
//         q.push(INT_MAX);
//         while(q.size()>0){
//             int u=q.front();
//             q.pop();
//             if(u==INT_MAX){
//                 if(q.empty()){
//                     break;
//                 }else{
//                     q.push(INT_MAX);
//                     height++;
//                     continue;
//                 }
//             }
//             for(auto &v:adj[u]){
//                 if(!visited[v]){
//                     q.push(v);
//                     visited[v]=true;
//                 }
//             }
//         }
//         return height;
//     }
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> adj(n);
//         vector<int> answer;
//         int minHeight=INT_MAX;
//         for(auto &e:edges){
//             adj[e[0]].push_back(e[1]);
//             adj[e[1]].push_back(e[0]);
//         }
//         for(int i=0;i<n;i++){
//             vector<bool> visited(n,false);
//             int h=bfs(i,visited,adj);
//             if(h<minHeight){
//                 minHeight=h;
//                 answer.clear();
//                 answer.push_back(i);
//             }else if(h==minHeight){
//                 answer.push_back(i);
//             }
//         }
//         return answer;
//     }
// };