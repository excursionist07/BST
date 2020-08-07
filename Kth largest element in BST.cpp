void inorder1(Node *root,int k,int &cnt)
{

  if(root==NULL)
    return;
  inorder1(root->right,k,cnt);
  cnt++;
  if(cnt==k)
  {
    cout<<root->key<<endl;
    return;
  }

  inorder1(root->left,k,cnt);
}


void kthLargest(Node *root, int k)
{
   int cnt=0;
  inorder1(root,k,cnt);


}
