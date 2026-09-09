class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        long long k=999; 
        while(n>k){
            ans+=n-k;
            if(n>k){
                k= k*1000+ 999;
            }
        }
        return ans;
    }
};