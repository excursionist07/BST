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

node *Insert(node *root,ll x)
{
 if(root==NULL)
    root=GetNewNode(x);
 else if(x<=root->data)
    root->left=Insert(root->left,x);
 else
    root->right=Insert(root->right,x);
 return root;
}

void LevelOrder(node *root)
{
 queue<node*>q;
 q.push(root);
 while(!q.empty())
 {
  node *cur=q.front();
  cout<<cur->data<<" ";
  q.pop();
  if(cur->left)q.push(cur->left);
  if(cur->right)q.push(cur->right);
 }
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
  LevelOrder(root);
 }
 return 0;
}