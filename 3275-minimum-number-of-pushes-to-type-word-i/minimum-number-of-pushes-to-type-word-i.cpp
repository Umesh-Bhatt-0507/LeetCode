class Solution {
public:
    int minimumPushes(string word) {
        int size=word.size();
        int rem=size%8;
        int que=size/8;
        rem*=(que+1);
        int mul=0;
        while(que!=0){
            mul+=que;
            que--;
        }
        return 8*(mul)+rem;
        
    }
};