class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum=n*n;
        int evenSum=n*(n+1);
        int x=min(oddSum,evenSum);
        for(int i=x;i>=1;i--){
            if(oddSum%i==0 && evenSum%i==0){
                return i;
            }
        }
        return 1;
    }
};