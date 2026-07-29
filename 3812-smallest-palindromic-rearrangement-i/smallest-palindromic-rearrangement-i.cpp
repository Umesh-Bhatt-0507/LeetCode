class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        int mid=n/2;
        sort(s.begin(),s.begin()+mid);
        for(int i=0;i<mid;i++){
            s[n-1-i]=s[i];
        }
        return s;
        


        // string ans="";
        // int l=0;
        // int r=s.size();
        // int mid=l+(r-l)/2;
        // for(int i=0;i<mid;i++){
        //     ans+=s[i];
        // }
        // sort(ans.begin(),ans.end());
        // string x=ans;
        // sort(x.rbegin(),x.rend());
        // if(s.size()%2!=0){
        //     return ans+s[mid]+x;
        // }
        // return ans+x;
    }
};