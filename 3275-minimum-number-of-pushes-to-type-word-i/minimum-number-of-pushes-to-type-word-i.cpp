class Solution {
public:
    int minimumPushes(string word) {
        int len=word.size();
        int count=0;
        int i=1;
        while(len>0){
            count+=min(len,8)*i;
            i++;
            len=len-8;
        }
        return count;
    }
};