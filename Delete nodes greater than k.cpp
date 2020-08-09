Node *FindMin(Node *root)
{
  if(root==NULL)
    return NULL;
  else if(root->left==NULL)
    return root;
  else
     FindMin(root->left);
}

Node *Delete(Node *root,int y)
{
  if(root==NULL)
    return NULL;
  else if(y<root->data)
     root->left=Delete(root->left,y);
  else if(y>root->data)
     root->right=Delete(root->right,y);
  else
  {
      //No child
  if(root->left==NULL && root->right==NULL)
  {
     delete root;
     root=NULL;
     return root;
  }
  // one child
  else if(root->left==NULL)
  {
     Node *temp=root;
     root=root->right;
     delete temp;
     return root;
  }
  else if(root->right==NULL)
  {
    Node *temp=root;
    root=root->left;
    delete temp;
    return root;

  }
  // Two child
  else
  {
    Node *temp=FindMin(root->right);
    root->data=temp->data;
    root->right=Delete(root->right,temp->data);
    return root;
  }
  }

  return root;
}
