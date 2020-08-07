In Binary Tree, Inorder successor of a node is the next node in Inorder traversal of the Binary Tree. Inorder Successor is NULL for the last node in Inorder traversal.
 
Node *minValue(Node *root)
{
 if(root==NULL)
  return NULL;
 else if(root->left==NULL)
   return root;
 else
   minValue(root->left);
}
Node * inOrderSuccessor(Node *root, Node *x)// O(h) && O(1)
{
  if(x->right!=NULL)
    return minValue(x->right);
 Node *succ=NULL;
 while(root!=NULL)
 {
  if(root->data>x->data)
  {
    succ=root;
    root=root->left;
  }
  else if(root->data<x->data)
    root=root->right;
  else
    break;
 }
 return succ;
}
