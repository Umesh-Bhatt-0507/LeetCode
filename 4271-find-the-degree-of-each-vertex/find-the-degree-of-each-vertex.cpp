class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> answer;
        for(int i=0;i<matrix.size();i++){
            int count=0;
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==1){
                    count++;
                }
            }
            answer.push_back(count);
        }
        return answer;
    }
};