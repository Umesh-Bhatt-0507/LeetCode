class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> m;
        for(auto &k:knowledge){
            m[k[0]]=k[1];
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                i++;
                string temp="";
                while(s[i]!=')'){
                    temp+=s[i];
                    i++;
                }
                bool found=false;
                if(m.count(temp)){
                    ans+=m[temp];
                    found=true;
                }
                if(!found){
                    ans+='?';
                }
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};