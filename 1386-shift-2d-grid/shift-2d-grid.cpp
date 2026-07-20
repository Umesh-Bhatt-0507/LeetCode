class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> store;
        for(int i=grid.size()-1;i>=0;i--){
            for(int j=grid[i].size()-1;j>=0;j--){
                store.push_back(grid[i][j]);
            }
        }
        int a=0;
        while(a<k){
            store.push_back(store[a++]);
        }
         for(int i=grid.size()-1;i>=0;i--){
            for(int j=grid[i].size()-1;j>=0;j--){
                grid[i][j]=store[a++];
            }
        }
        return grid;
    }
};