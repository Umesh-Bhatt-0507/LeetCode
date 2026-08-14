class Solution {
public:
    int maximumLengthSubstring(string s) {
        int right=0;
        int left=0;
        int ans=INT_MIN;
        unordered_map<int,int> store;
        while(right<s.size()){
            store[s[right]]++;
            if(store[s[right]]>2){
                while(store[s[right]]>2){
                    store[s[left]]--;
                    left++;
                }
            }
            int val=right-left;
            ans=max(val,ans);
            right++;
        }
        return ans+1;
    }
};