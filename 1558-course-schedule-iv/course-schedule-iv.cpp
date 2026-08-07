class Solution {
public:
    vector<bool> answer;
    void helper(int a,int b,vector<vector<int>> adj){
        vector<bool> visited(adj.size(),false);
        queue<int> q;
        q.push(a);
        visited[a]=true;
        while(q.size()>0){
            int u=q.front();
            q.pop();
            if(u==b){
                answer.push_back(true);
                return;
            }
            for(auto &v:adj[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=true;
                }
            }
        }
        answer.push_back(false);
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        for(auto &u:prerequisites){
            adj[u[0]].push_back(u[1]);
        }
        for(auto &u:queries){
            helper(u[0],u[1],adj);
        }
        return answer; 
    }
};
















// class Solution {
// public:
//     void helper(int &numCourses,vector<int> inDegree,vector<bool> &answer,int a,int b,vector<vector<int>> &l){
//         queue<int> q;
//         for(int i=0;i<numCourses;i++){
//             if(inDegree[i]==0){
//                 q.push(i);
//             }
//         }
//         while(q.size()>0){
//             int u=q.front();
//             q.pop();
//             for(auto &v:l[u]){
//                 inDegree[v]--;
//                 if(inDegree[a]==0 && inDegree[b]==0){
//                     answer.push_back(false);
//                     return;
//                 }
//                 if(inDegree[a]==0){
//                     answer.push_back(true);
//                     return;
//                 }
//                 if(inDegree[b]==0){
//                     answer.push_back(false);
//                     return;
//                 }
//                 if(inDegree[v]==0){
//                     q.push(v);
//                 }
//             }
//         }
//     }
//     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//         vector<vector<int>> l(numCourses);
//         for(auto &v:prerequisites){
//             l[v[0]].push_back(v[1]);
//         }
//         vector<bool> answer;
//         vector<int> inDegree(numCourses,0);
//         for(auto &v:prerequisites){
//             inDegree[v[1]]++;
//         }
//         for(auto &v:queries){
//             helper(numCourses,inDegree,answer,v[0],v[1],l);
//         }
//         return answer;
//     }
// };