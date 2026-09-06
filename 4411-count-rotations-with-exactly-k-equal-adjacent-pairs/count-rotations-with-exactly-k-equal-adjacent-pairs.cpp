class Solution {
public:
    int countRotations(string s, int k) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            s+=s[i];
        }
        for(int i=0;i<n;i++){
            int score=0;
            for(int j=i+1;j<i+n;j++){
                if(s[j]==s[j-1]){
                    score++;
                }
            }
            if(score==k){
                ans++;
            }
            score=0;
        }
        return ans;
    }
};