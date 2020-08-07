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

struct node
{
  ll data;
  node *left;
  node *right;
};

node *GetNewNode(ll x)
{
 node *temp=new node();
 temp->data=x;
 temp->left=temp->right=NULL;
 return temp;

}

node *FindMin(node *root)
{
 if(root==NULL)
    return NULL;
 else if(root->left==NULL)
    return root;
 else
    FindMin(root->left);

}
node* Insert(node *root,ll x)
{
 if(root==NULL)
    root=GetNewNode(x);
  if(x>root->data)
    root->right=Insert(root->right,x);
  if(x<root->data)
    root->left=Insert(root->left,x);
 return root;
}

node *Delete(node *root,ll y)
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
    // One child
    else if(root->left==NULL)
    {
      node *temp=root;
      root=root->right;
      delete temp;
      return root;
    }
    else if(root->right==NULL)
    {
     node *temp=root;
     root=root->left;
     delete temp;
     return root;
    }
    // two child
    else
    {
      node *temp=FindMin(root->right);
      root->data=temp->data;
      root->right=Delete(root->right,temp->data);
      return root;
    }
  }
}
void Inorder(node *root)
{
  if(root==NULL)
        return;
  Inorder(root->left);
  cout<<root->data<<" ";
  Inorder(root->right);
}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  node *root=NULL;
  ll n;
  cin>>n;
  f(n)
  {
   ll x;
   cin>>x;
   root=Insert(root,x);
  }
  ll btao;
  cin>>btao;
  f(btao)
  {
    ll y;
    cin>>y;
    Delete(root,y);
    Inorder(root);
    cout<<"\n";

  }

 }
 return 0;
}

/*
1) Node to be deleted is leaf: Simply remove from the tree.
2) Node to be deleted has only one child: Copy the child to the node and delete the child.
3) Node to be deleted has two children: Find inorder successor of the node. Copy contents of the inorder successor to the node and delete the inorder successor. 
Note that inorder predecessor can also be used.
*/
