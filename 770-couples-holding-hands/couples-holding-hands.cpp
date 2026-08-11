class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int swaps=0;
        vector<int> positions(row.size());
        for(int i=0;i<row.size();i++){
            positions[row[i]]=i;
        }
        for(int i=0;i<row.size();i+=2){
            int next=( row[i]%2==0 ) ? row[i]+1 : row[i]-1;
            if(row[i+1]!=next){
                int to=positions[next];
                positions[row[i+1]]=to;
                positions[row[to]]=i+1;
                swap(row[i+1],row[to]);
                swaps++;
            }
        }
        return swaps;
    }
};