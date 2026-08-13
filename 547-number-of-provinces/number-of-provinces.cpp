class Solution {
public:
    vector<int> par,rank;
    int count;
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
            return;
        }
        if(rank[parA]==rank[parB]){
            par[parB]=parA;
            rank[parA]++;
        }else if(rank[parA]> rank[parB]){
            par[parB]=parA;
        }else{
            par[parA]=parB;
        }
        count--;
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        count=isConnected.size();
        for(int i=0;i<isConnected.size();i++){
            rank.push_back(0);
            par.push_back(i);
        }
        for(int i=0;i<isConnected.size();i++){
            for(int j=i+1;j<isConnected.size();j++){
                if(isConnected[i][j]==1){
                    unionByRank(i,j);
                }
            }
        }
        return count;
    }
};