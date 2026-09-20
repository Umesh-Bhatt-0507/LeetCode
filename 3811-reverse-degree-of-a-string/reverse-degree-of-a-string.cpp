class Solution {
public:
    int reverseDegree(string s) {
        int total=0;
        for(int i=0;i<s.size();i++){
            total+= (97-int(s[i])+26)*(i+1);
        }
        return total;
    }
};