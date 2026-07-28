class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }
        vector<vector<bool>> vis(image.size(),vector<bool> (image[0].size(),false));
        int init=image[sr][sc];
        queue<pair<int,int>> store;
        store.push({sr,sc});
        // image[sr][sc]=color;
        while(!store.empty()){
            int i=store.front().first;
            int j=store.front().second;
            store.pop();
            image[i][j]=color;
            cout<<i<<" "<<j<<endl;
            if(i>0 && image[i-1][j]==init && !vis[i-1][j]){
                store.push({i-1,j});
                vis[i-1][j]=true;
            }
            if(j>0 && image[i][j-1]==init && !vis[i][j-1]){
                store.push({i,j-1});
                vis[i][j-1]=true;
            }
            if(i<image.size()-1 && image[i+1][j]==init && !vis[i+1][j]){
                store.push({i+1,j});
                vis[i+1][j]=true;
            }
            if(j<image[0].size()-1 && image[i][j+1]==init && !vis[i][j+1]){
                store.push({i,j+1});
                vis[i][j+1]=true;
            } 
        }
        return image;



        // queue<pair<int,int>> store;
        // store.push({sr,sc});
        // int val=image[sr][sc];
        // int max_time=(image.size())*(image[0].size());
        // int count=0;
        // while(!store.empty()){
        //     int a=store.front().first;
        //     int b=store.front().second;
        //     store.pop();
        //     image[a][b]=color;
        //     count++;
        //     if(count>max_time){
        //         break;
        //     }
        //     if(a>0 && image[a-1][b]==val){
        //         store.push({a-1,b});
        //     }
        //     if(a<image.size()-1 && image[a+1][b]==val){
        //         store.push({a+1,b});
        //     }
        //     if(b>0 && image[a][b-1]==val){
        //         store.push({a,b-1});
        //     }
        //     if(b<image[0].size()-1 && image[a][b+1]==val){
        //         store.push({a,b+1});
        //     }
        // }
        // return image;
    }
};