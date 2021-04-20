
class Solution {
public:
    TreeNode* FindMin(TreeNode* root)
    {
     if(!root)
         return NULL;
     else if(!root->left)
         return root;
     else
        return FindMin(root->left);
    
    }
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
     if(!root)
         return NULL;
     else if(root->val>key)
         root->left=deleteNode(root->left,key);
     else if(root->val<key)
         root->right=deleteNode(root->right,key);
     else
     {
      // no child
      if(!root->left && !root->right)
      {
       delete root;
       root=NULL;
       return root;
      }
      // one child
      else if(!root->left)
      {
       TreeNode* temp=root;
       root=root->right;
       delete temp;
       return root;
      }
      else if(!root->right)
      {
       TreeNode* temp=root;
       root=root->left;
       delete temp;
       return root;
      }
      // two child
      else
      {
       TreeNode* temp=FindMin(root->right);
       root->val=temp->val;
       root->right=deleteNode(root->right,temp->val);
       return root;
      }
     }
     return root;
         
       
    }
};
