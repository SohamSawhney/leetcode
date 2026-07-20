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
   bool symmetric(TreeNode* p,TreeNode* q){
    if(p==NULL and q==NULL){
        return 1;
    }
    if((!p and q) or (p and !q)){
        return 0;
    }
    if(p->val !=q->val){
        return 0;
    }

    return symmetric(p->left,q->right) and symmetric(p->right,q->left);
   }
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return 1;
        }
       return symmetric(root->left,root->right);


        
    }
};