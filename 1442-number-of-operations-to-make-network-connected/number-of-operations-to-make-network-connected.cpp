class Solution {
public:
    int count;
    int extraWires;
    vector<int> par,rank;
    int find(int x){
        if(x==par[x]){
            return x;
        }
        return par[x]=find(par[x]);
    }

    void unionByRank(int a,int b){
        int parA=find(a);
        int parB=find(b);
        if(parA==parB){
            extraWires++;
            return;
        }
        if(rank[parA]==rank[parB]){
            par[parB]=parA;
            rank[parA]++;
        }else if(rank[parA]>rank[parB]){
            par[parB]=parA;
        }else{
            par[parA]=parB;
        }
        count++;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        count=0;
        extraWires=0;
        for(int i=0;i<n;i++){
            par.push_back(i);
            rank.push_back(0);
        }
        for(int i=0;i<connections.size();i++){
            unionByRank(connections[i][0],connections[i][1]);
        }
        int notConnected=n-count-1;
        if(extraWires <notConnected){
            return -1;
        }
        return notConnected;
    }
};