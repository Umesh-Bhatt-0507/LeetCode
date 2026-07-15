class Solution {
public:
    void helper(vector<vector<int>>& rooms,set<int> &store,int src){
        store.erase(src);
        for(auto v:rooms[src]){
            if(store.count(v)){
                helper(rooms,store,v);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> store;
        for(int i=0;i<rooms.size();i++){
            store.insert(i);
        }
        helper(rooms,store,0);      
        if(store.empty()){
            return true;
        }
        return false;
    }
};