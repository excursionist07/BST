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

Node* LCA(Node *root, int n1, int n2)
{
  if(root==NULL)
   return NULL;
  if(root->data>n1 && root->data>n2)
    return LCA(root->left,n1,n2);
  if(root->data<n1 && root->data<n2)
    return LCA(root->right,n1,n2);
  return root;
}

O(h)
