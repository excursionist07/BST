#include <bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repush_back(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define F first
#define S second
#define pi 3.14159265359
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
ll HRX=1e18;
ll INF=1e9+7;

#include<vector>
vector<int>vec;

Node* temp2;

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
void in(Node *root,int x)
{

  if(root==NULL)
    return;
  in(root->left,x);
  if(root->data>=x)
     vec.push_back(root->data);
  in(root->right,x);
 // return temp2;
}
/*void in2(Node *root)
{
  if(root==NULL)
    return;
  in2(root->left);
  cout<<root->data<<" ";
  in2(root->right);
}*/
Node* deleteNode(Node* root, int key)
{
  // Node* temp1=root;
  // Node* temp2=root;
    vec.clear();
   in(root,key);
   Node *temp2=root;
   for(int i=0;i<vec.size();i++)
   {
     temp2=Delete(temp2,vec[i]);
   }
   return temp2;




}
