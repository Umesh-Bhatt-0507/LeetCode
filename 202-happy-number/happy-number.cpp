class Solution {
public:
    int ss(int n){
        int sum=0;
        while(n!=0){
            int d=n%10;
            n=n/10;
            sum+=d*d;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=ss(n);
        int fast=ss(ss(n));
        while(slow!=fast){
            slow=ss(slow);
            fast=ss(ss(fast));
        }
        if(slow==1){
            return true;
        }
        return false;

        // int temp=n;
        // int sq;
        // int ch=0;
        // int a=0;
        // while(a<10){
        //     while(temp!=0){
        //         sq=temp%10;
        //         ch+=sq*sq;
        //         temp=temp/10;
        //     }
        //     if(ch==1){
        //         return true;
        //     }
        //     temp=ch;
        //     ch=0;
        //     a++;
        // }
        // return false;



        // set<int> seen;
        // while(n!=1){
        //    if(seen.count(n)){
        //     return false;
        //    }
        //    seen.insert(n);
        //    int ch=0;
        //    while(n>0){
        //     int d=n%10;
        //     ch+=d*d;
        //     n=n/10;
        //    }
        //    n=ch;
        // }
        // return true;
    }
};