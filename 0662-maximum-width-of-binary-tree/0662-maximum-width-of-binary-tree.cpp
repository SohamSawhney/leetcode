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
    int widthOfBinaryTree(TreeNode* root) {

        if(!root){
            return 0;
        }

        int maxWidth=0;

        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){

            int n=q.size();
         
            int minidx=q.front().second;
            int first=0;
            int last=0;

            for(int i=0;i<n;i++){

                  TreeNode*node=q.front().first;
                  long currInd=q.front().second-minidx;
                  q.pop();


                  if(i==0){
                    first=currInd;
                  }
                  if(i==n-1){
                    last=currInd;
                  }


                  if(node->left){
                    q.push({node->left,2*currInd+1});
                  }
                  if(node->right){
                    q.push({node->right,2*currInd+2});
                  }
                  
           

            }

             maxWidth=max(maxWidth,last-first+1);
            




        }


        return maxWidth;

        
    }
};