In Binary Tree, Inorder predecessor of a node is the previous node in Inorder traversal of the Binary Tree. 


Node *MaxValue(Node *root)
{
 if(root==NULL)
  return NULL;
 else if(root->right==NULL)
   return root;
 else
   MaxValue(root->right);
}

Node * inOrderPredecessor(Node *root, Node *x)
{
 if(x->left!=NULL)
    return MaxValue(x->left);
 Node *pred=root;
 while(root!=NULL)
 {
  if(root->data>x->data)
    root=root->left;
  else if(root->data<x->data)
  {
   pred=root;
   root=root->right;
  }
  else
    break;
 }
 return pred;
}
