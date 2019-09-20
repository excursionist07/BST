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
