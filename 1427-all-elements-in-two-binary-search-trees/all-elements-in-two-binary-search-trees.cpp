/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode *root,vector<int> &store){
        if(root==NULL){
            return;
        }
        inorder(root->left,store);
        store.push_back(root->val);
        inorder(root->right,store);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> l1;
        vector<int> l2;
        vector<int> answer;
        inorder(root1,l1);
        inorder(root2,l2);
        int a=0;
        int b=0;
        while(a<l1.size() && b<l2.size()){
            if(l1[a]<l2[b]){
                answer.push_back(l1[a++]);
            }
            else{
                answer.push_back(l2[b++]);
            }
        }
        while(a<l1.size()){
            answer.push_back(l1[a++]);
        }
        while(b<l2.size()){
            answer.push_back(l2[b++]);
        }
        return answer;
    }
};