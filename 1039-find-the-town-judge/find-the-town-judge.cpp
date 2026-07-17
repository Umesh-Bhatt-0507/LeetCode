class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.empty() && n==1){
            return 1;
        }
        else if(trust.empty() && n>1){
            return -1;
        }
        map<int,int> store;
        for(int i=0;i<trust.size();i++){
            store[trust[i][1]]++;
        }
        for(int i=0;i<trust.size();i++){
            if(store.count(trust[i][0])){
                store.erase(trust[i][0]);
            }
        }
        if(store.empty()){
            return -1;
        }
        int b;
        for(auto it=store.begin();it!=store.end();++it){
            b=it->first;
        }
        if(store[b]!=(n-1)){
            return -1;
        }
        return b;




        // if(trust.size()==n){
        //     return -1;
        // }
        // set<int> store;
        // int count=0;
        // for(int i=0;i<trust.size();i++){
        //     store.insert(trust[i][0]);
        // }
        // int a;
        // for(int i=1;i<=n;i++){
        //     if(!store.count(i)){
        //         count++;
        //         if(count>1){
        //             return -1;
        //         }
        //         a=i;
                
        //     }
        // }
        // return a;

        
    }
};