class Solution {
public:
    int distance(int x1,int y1,int x2,int y2){
        return abs(x1-x2)+abs(y1-y2);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>> graph(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int w=distance(points[i][0],points[i][1],points[j][0],points[j][1]);
                graph[i].push_back({j,w});
                graph[j].push_back({i,w});
            }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<bool> inMST(n,false);
        int minCost=0;
        pq.push({0,0});
        while(pq.size()>0){
            int w=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(!inMST[u]){
                inMST[u]=true;
                minCost+=w;
                for(auto &v: graph[u]){
                    if(!inMST[v.first]){
                        pq.push({v.second,v.first});
                    }
                }
            }
        }
        return minCost;
    }
};