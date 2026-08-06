class Solution {
public:
    int smallestNumber(int n, int t) {
        if(n<10){
            while(n%t !=0){
                if(n%10==0){
                    return n;
                }
                n++;
            }
            return n;
        }
        int x=(n%10)*(n/10);
        while(x%t !=0){
            n++;
            x=(n%10)*(n/10);
        }
        return n;
    }
};