class Solution {
public:
    vector<int> par,rank;
    bool flag=false;
    int find(int x){
        if(x==par[x]){
            return x;
        }
        return par[x]=find(par[x]);
    }
    void unionByRank(int a,int b){
        int parA= find(a);
        int parB=find(b);
        if(parA==parB){
            flag=true;
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
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        par.push_back(0);
        rank.push_back(0);
        for(int i=1;i<=edges.size();i++){
            par.push_back(i);
            rank.push_back(0);
        }
        for(auto &e:edges){
            unionByRank(e[0],e[1]);
            if(flag){
                return e;
            }
        }
        return {};
    }
};