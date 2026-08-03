/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int max=0;
    void helper(Node* root,int count){
        if(root->children.size()==0){
            if(max < count){
                max=count;
            }
            return;
        }
        for(auto v: root->children){
            helper(v,count+1);
        }
    }
    int maxDepth(Node* root) {
        if(root==NULL){
            return 0;
        }
        helper(root,1);
        return max;
    }
};