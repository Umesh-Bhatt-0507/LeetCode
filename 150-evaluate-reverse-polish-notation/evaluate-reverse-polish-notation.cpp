class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int a,b,c;
        stack<int> store;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+"  && tokens[i]!="-"  && tokens[i]!="*"  && tokens[i]!="/"){
                store.push(stoi(tokens[i]));
                c=store.top();
            }
            else{
                if(tokens[i]=="+"){
                    a=store.top();
                    store.pop();
                    b=store.top();
                    store.pop();
                    c=a+b;
                    store.push(c);
                }
                else if(tokens[i]=="*"){
                    a=store.top();
                    store.pop();
                    b=store.top();
                    store.pop();
                    c=a*b;
                    store.push(c);
                }
                else if(tokens[i]=="-"){
                    a=store.top();
                    store.pop();
                    b=store.top();
                    store.pop();
                    c=b-a;
                    store.push(c);
                }
                else if(tokens[i]=="/"){
                    a=store.top();
                    store.pop();
                    b=store.top();
                    store.pop();
                    c=b/a;
                    store.push(c);
                }
            }
        }
        return c;
    }
};