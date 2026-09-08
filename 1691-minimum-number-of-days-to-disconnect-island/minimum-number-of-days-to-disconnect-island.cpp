class Solution {
public:
    int m,n;
    void DFS(int i,int j,vector<vector<int>>& grid,vector<vector<bool>> &visited){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0 || visited[i][j]){
            return;
        }
        visited[i][j]=true;
        DFS(i+1,j,grid,visited);
        DFS(i-1,j,grid,visited);
        DFS(i,j+1,grid,visited);
        DFS(i,j-1,grid,visited);
    }

    int noOfIslands(vector<vector<int>>& grid){
        int islands=0;
        vector<vector<bool>> visited(m,vector<bool> (n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    DFS(i,j,grid,visited);
                    islands++;
                }

            }
        }
        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        int islands=noOfIslands(grid);
        if(islands!=1){
            return 0;
        }else{
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1){
                        grid[i][j]=0;
                        islands=noOfIslands(grid);
                        if(islands!=1){
                            return 1;
                        }
                        grid[i][j]=1;
                    }
                }
            }
        }
        return 2;
    }
};