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
    int dec,ans;
    void in(TreeNode* root)
    {
      if(!root)
          return;
      in(root->left);
      dec--;
      if(dec==0)
          ans=root->val;
      in(root->right);

    }

    int kthSmallest(TreeNode* root, int k)
    {
     dec=k;
     in(root);
     return ans;

    }
};
