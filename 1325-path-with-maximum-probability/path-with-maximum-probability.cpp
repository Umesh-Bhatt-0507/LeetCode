class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> dist(n,0);
        dist[start_node]=1;
        priority_queue<pair<double,int>> pq;
        pq.push({dist[start_node],start_node});
        while(pq.size()>0){
            int u=pq.top().second;
            pq.pop();
            for(auto &e:graph[u]){
                if(dist[e.first] < dist[u]*e.second){
                    dist[e.first] = dist[u]*e.second;
                    pq.push({dist[e.first],e.first});
                }
            }
        }
        return dist[end_node];
    }
};