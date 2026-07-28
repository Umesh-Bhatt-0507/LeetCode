class Solution {
public:
    bool helper(int u,vector<bool> &vis,vector<bool> &recPath,list<int> store[]){
        vis[u]=true;
        recPath[u]=true;
        for(int v:store[u]){
            if(!vis[v]){
                if(helper(v,vis,recPath,store)){
                    return true;
                }
            }else if(recPath[v]){
                return true;
            }
        }
        recPath[u]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        list<int> store [numCourses];
        for(int i=0;i<prerequisites.size();i++){
            store[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool> visited(numCourses,false);
        vector<bool> recPath(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(helper(i,visited,recPath,store)){
                    return false;
                }
            }
        }
        return true;
    }
};