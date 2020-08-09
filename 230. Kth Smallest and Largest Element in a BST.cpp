
class Solution {
public:
    int dec,ans;
    void in(TreeNode* root)//O(n) worst case
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



int ans;
void doit(Node* root,int& K)
{
 if(!root)
  return;
 doit(root->right,K);
 K--;
 if(K==0)
  ans=root->data;
 doit(root->left,K);
}
int kthLargest(Node *root, int K)
{
  if(!root)
   return -1;
 doit(root,K);
  return ans;
}
