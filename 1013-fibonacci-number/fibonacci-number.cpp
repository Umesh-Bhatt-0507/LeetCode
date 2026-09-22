class Solution {
public:
    int fib(int n) {
        // vector<int> dp(n+1;-1);
        // dp[0]=0;
        // dp[1]=1;
        if(n==0 || n==1){
            return n;
        }
        return fib(n-1)+fib(n-2);
    }
};