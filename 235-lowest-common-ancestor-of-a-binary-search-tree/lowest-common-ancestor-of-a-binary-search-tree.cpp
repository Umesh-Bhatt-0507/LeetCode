/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root==p || root==q){
            return root;
        }
        TreeNode *left=lowestCommonAncestor(root->left,p,q);
        TreeNode *right=lowestCommonAncestor(root->right,p,q);
        if(left !=NULL && right!=NULL){
            return root;
        }else if(left!=NULL){
            return left;
        }else{
            return right;
        }
    }
};





// class Solution {
// public:
//     bool travel(TreeNode *root,int val){
//         if(root==NULL){
//             return false;
//         }
//         if(root->val==val){
//             return true;
//         }
//         return (travel(root->left,val) || travel(root->right,val));
//     }
//     bool  check(TreeNode* root, TreeNode* p, TreeNode* q){
//         queue<TreeNode *> store;
//         store.push(root);
//         while(!store.empty()){
//             TreeNode *temp=store.front();
//             store.pop();
//             return (travel(temp,p->val) && travel(temp,q->val));
//         }
        
//         return false;
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(p->left && p->left == q || p->right && p->right==q){
//             return p;
//         }
//         if(q->left && q->left == p || q->right && q->right==p){
//             return q;
//         }
//         TreeNode *answer=root;
//         queue<TreeNode *> store;
//         store.push(answer);
//         while(!store.empty()){
//             TreeNode *temp=store.front();
//             store.pop();
//             if(temp->left && check(temp->left,p,q)){
//                 store.push(temp->left);
//                 answer=temp->left;
//             }
//             if(temp->right && check(temp->right,p,q)){
//                 store.push(temp->right);
//                 answer=temp->right;
//             }
//         }
//         return answer;
//     }
// };