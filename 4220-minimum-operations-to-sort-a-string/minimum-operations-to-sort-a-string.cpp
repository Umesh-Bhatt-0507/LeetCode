class Solution {
public:
    int minOperations(string s) {
        // int n=s.size();
        // string temp;
        // if(n==1){
        //     return 0;
        // }else if(n==2){
        //     temp=s;
        //     sort(temp.begin(),temp.end());
        //     if(s.compare(temp)==0){
        //         return 0;
        //     }else{
        //         return -1;
        //     }
        // }else{
        //     temp=s;
        //     sort(temp.begin(),temp.end());
        //     if(s.compare(temp)==0){
        //         return 0;
        //     }else{
        //         string s1=s.substr(0,n-1);
        //         string s2=s.substr(1,n);
        //         sort(s1.begin(),s1.end());
        //         sort(s2.begin(),s2.end());
        //         if(temp.compare(s1+s[n-1])==0 || temp.compare(s[0]+s2)==0){
        //             return 1;
        //         }
        //     }
        // }
        // return 2;

        int n=s.size();
        string temp=s;
        sort(temp.begin(),temp.end());
        if(temp==s){
            return 0;
        }
        if(n==1){
            return 0;
        }
        if(n==2){
            return -1;
        }
        char mn=s[0];
        char mx=s[0];
        for(int i=1;i<n;i++){
            if(s[i]<mn){
                mn= s[i];
            }
            if(s[i]>mx){
                mx=s[i];
            }
        }
        if(s[0]==mn || s[n-1]==mx){
            return 1;
        }
        bool hasInnerExtreme=false;
        for(int i=1;i<n-1;i++){
            if(s[i]==mn || s[i]==mx){
                hasInnerExtreme=true;
                break;
            }
        }
        if(hasInnerExtreme){
            return 2;
        }
        return 3;
    }
};