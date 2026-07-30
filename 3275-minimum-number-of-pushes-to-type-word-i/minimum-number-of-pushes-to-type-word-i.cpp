class Solution {
public:
    int minimumPushes(string word) {
        int size=word.size();
        int quo=size/8;
        int rem=size%8* (quo+1);
        int mul=0;
        while(quo!=0){
            mul+=quo;
            quo--;
        }
        return 8*(mul)+rem;
        
    }
};