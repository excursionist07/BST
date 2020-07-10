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
    /*vector<int>vv;
    void in(TreeNode* root)
    {
     if(!root)
         return;
     /*in(root->left);
     vv.push_back(root->val);
     in(root->right);
    }*/
    bool doit(TreeNode* root,long long int minn,long long int maxx)
    {
     if(!root)
         return true;
     if(root->val<=minn || root->val>=maxx)
         return false;
     if(!doit(root->left,minn,root->val) || !doit(root->right,root->val,maxx))
         return false;
     return true;
    }
    bool isValidBST(TreeNode* root)
    {
     /* vv.clear();
      if(!root)
          return 1;
      in(root);
      for(int i=1;i<vv.size();i++)
      {
       if(vv[i]<=vv[i-1])
           return 0;
      }
      return 1;*/
      if(!root)
          return true;
     
      return doit(root,-1e18,1e18);
    }
};
