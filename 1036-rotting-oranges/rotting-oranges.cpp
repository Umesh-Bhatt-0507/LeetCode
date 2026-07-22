class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0;
        queue<vector<int>> store;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    store.push({i,j});
                }
            }
        }
        store.push({-1,-1});
        while(!store.empty()){
            vector<int> get=store.front();
            int i=get[0];
            int j=get[1]; 
            store.pop();
            if(i<0 && !store.empty()){
                store.push({-1,-1});
                count++;
                continue;
            }
            if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
                continue;
                if(store.empty()){
                    break;
                }
            }
            if(j+1<grid[0].size() && grid[i][j+1]==1) {
                grid[i][j+1] = 2;
                store.push({i, j + 1});
            }
            if(j-1 >= 0 && grid[i][j-1]==1) {
                grid[i][j - 1] = 2;
                store.push({i, j - 1});
            }
            if(i+1<grid.size() && grid[i+1][j]==1){
                grid[i+1][j]=2;
                store.push({i+1,j});
            }
            if(i-1>=0 && grid[i-1][j]==1){
                grid[i-1][j]=2;
                store.push({i-1,j});
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return count;
    }
};