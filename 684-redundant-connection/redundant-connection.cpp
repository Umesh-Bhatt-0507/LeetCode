class Solution {
public:
    vector<int> par,rank;
    int find(int x){
        if(x==par[x]){
            return x;
        }
        return par[x]=find(par[x]);
    }
    vector<int> unionByRank(int a,int b){
        int parA= find(a);
        int parB=find(b);
        if(parA==parB){
            return {a,b};
        }
        if(rank[parA]==rank[parB]){
            par[parB]=parA;
            rank[parA]++;
        }else if(rank[parA]>rank[parB]){
            par[parB]=parA;
        }else{
            par[parA]=parB;
        }
        return {};
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i=0;i<=edges.size();i++){
            par.push_back(i);
            rank.push_back(0);
        }
        for(auto &e:edges){
            vector<int> v=unionByRank(e[0],e[1]);
            if(v.size()>1){
                return v;
            }
        }
        return {};
    }
};