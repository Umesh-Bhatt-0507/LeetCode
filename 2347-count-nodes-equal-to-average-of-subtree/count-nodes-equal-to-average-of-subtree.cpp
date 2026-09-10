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
    void preorder(TreeNode *root,int &sum,int &count){
        if(root==NULL){
            return;
        }
        sum+=root->val;
        count++;
        preorder(root->left,sum,count);
        preorder(root->right,sum,count);
    }
    int averageOfSubtree(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int count=0;
        while(!q.empty()){
            TreeNode *temp=q.front();
            q.pop();
            int sum=0;
            int total=0;
            preorder(temp,sum,total);
            cout<<sum<<" "<<total<<" "<<endl;
            if(total!=0 && sum/total == temp->val){
                count++;
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        return count;
    }
};