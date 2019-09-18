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

Node *FindMin(Node *root)
{
 if(root==NULL)
   return NULL;
 else if(root->left==NULL)
    return root;
 else
   FindMin(root->left);

}
Node *deleteNode(Node *root,  int x)
{
  if(root==NULL)
    return NULL;
  else if(x<root->data)
    root->left=deleteNode(root->left,x);
  else if(x>root->data)
    root->right=deleteNode(root->right,x);
  else
  {
     // no child
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
     // two child
     else
     {
       Node *temp=FindMin(root->right);
       root->data=temp->data;
       root->right=deleteNode(root->right,temp->data);
       return root;
     }
  }
}
