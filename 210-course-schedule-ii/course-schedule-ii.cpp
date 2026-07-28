class Solution {
public:
    bool dfs(int u,vector<bool> &visited,stack<int> &store,list<int> l[],vector<bool> &recPath){
        visited[u]=true;
        recPath[u]=true;
        for(int v:l[u]){
            if(!visited[v]){
                if(dfs(v,visited,store,l,recPath)){
                    return true;
                }
            }else if(recPath[v]){
                return true;
            }
        }
        store.push(u);
        recPath[u]=false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        list<int> l [numCourses];
        stack<int> store;
        vector<int> answer;
        vector<bool> visited(numCourses,false);
        vector<bool> recPath(numCourses,false);
        for(int i=0;i<prerequisites.size();i++){
            l[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        bool flag=true;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,visited,store,l,recPath)){
                    flag=false;
                }
            }
        }
        if(!flag){
            return answer;
        }
        while(!store.empty()){
            answer.push_back(store.top());
            store.pop();
        }
        return answer;
    }
};