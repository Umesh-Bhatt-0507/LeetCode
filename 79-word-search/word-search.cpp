class Solution {
public:
    bool dfs(char curr,int idx,string word,string &target,int i, int j,vector<vector<char>>& board,vector<vector<bool>> &visited){
        if(curr!=target[idx]){
            return false;
        }
        visited[i][j]=true;
        word+=curr;
        if(idx==target.size()-1){
            return true;
        }
        bool top=false;
        bool right=false;
        bool bottom=false;
        bool left=false;
        if(j>0 && !visited[i][j-1]){
            left=dfs(board[i][j-1],idx+1,word,target,i,j-1,board,visited);
        }
        if(i>0 && !visited[i-1][j]){
            top=dfs(board[i-1][j],idx+1,word,target,i-1,j,board,visited);
        }
        if(i<board.size()-1 && !visited[i+1][j]){
            right=dfs(board[i+1][j],idx+1,word,target,i+1,j,board,visited);
        }
        if(j<board[0].size()-1 && !visited[i][j+1]){
            bottom=dfs(board[i][j+1],idx+1,word,target,i,j+1,board,visited);
        }
        visited[i][j]=false;
        return (top||left|| right|| bottom);
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    if(dfs(word[0],0,"",word,i,j,board,visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};