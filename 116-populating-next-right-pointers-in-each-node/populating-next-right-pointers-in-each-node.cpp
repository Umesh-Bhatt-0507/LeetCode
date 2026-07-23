/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        vector<Node *> v;
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node *f=q.front();
            q.pop();
            if(!f){
                if(q.empty()){
                    break;
                }
                q.push(f);
                v.push_back(f);
                continue;
            }
            v.push_back(f);
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
        for(int i=0;i<v.size()-1;i++){
            if(v[i]!=NULL){
                cout<<v[i]->val<<" ";
                v[i]->next=v[i+1];
            }else{
                cout<<0<<" ";
            }
        }
        return root;

    }
};