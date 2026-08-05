class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> answer;
        vector<vector<int>> graph(n);
        for(auto &u:invocations){
            graph[u[0]].push_back(u[1]);
        }
        vector<int> visited(n,false);
        queue<int> q;
        q.push({k});
        visited[k]=true;
        while(q.size()>0){
            int u=q.front();
            q.pop();
            for(auto v: graph[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=true;
                }
            }
        }
        for(int i=0;i<invocations.size();i++){
            if(!visited[invocations[i][0]] && visited[invocations[i][1]]){
                for(int i=0;i<n;i++){
                    visited[i]=false;
                }
                break;
            }
            if(!visited[invocations[i][1]]){
                visited[invocations[i][0]]=false;
            }
            if(!visited[invocations[i][0]]){
                visited[invocations[i][1]]=false;
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                answer.push_back(i);
            }
        }
        return answer;
    }
};