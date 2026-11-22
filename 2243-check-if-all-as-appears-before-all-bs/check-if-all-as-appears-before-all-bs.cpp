class Solution {
public:
    bool checkString(string s) {
        // bool flag=false;
        // for(char c:s){
        //     if(c=='b'){
        //         flag=true;
        //     }
        //     if(c=='a' && flag){
        //         return false;
        //     }
        // }
        // return true;

        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='b' && s[i+1]=='a'){
                return false;
            }
        }
        return true;
    }
};