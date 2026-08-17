class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> graph[n];
        for(int i=0;i<flights.size();i++){
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> dist(n,INT_MAX);
        queue<pair<int,pair<int,int>>> pq;
        pq.push({src,{0,-1}});
        dist[src]=0;
        while(pq.size()> 0){
            int u=pq.front().first;
            int w=pq.front().second.first;
            int s=pq.front().second.second;
            pq.pop();
            for(auto v:graph[u]){
                if(dist[v.first] > w+ v.second  && s+1<=k){
                    dist[v.first]= w+ v.second;
                    pq.push({v.first,{dist[v.first],s+1}});
                }
            }
        }
        if(dist[dst]==INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};