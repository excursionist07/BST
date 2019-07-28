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

void preorder(node *root)
{
 if(root==NULL)
    return;
 cout<<root->data<<" ";
 preorder(root->left);
 preorder(root->right);
}

void inorder(node *root)
{
 if(root==NULL)
    return;
 inorder(root->left);
 cout<<root->data<<" ";
 inorder(root->right);
}

void postorder(node *root)
{
 if(root==NULL)
    return;
 postorder(root->left);
 postorder(root->right);
 cout<<root->data<<" ";
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
  preorder(root);
  cout<<"\n";
  inorder(root);
  cout<<"\n";
  postorder(root);
  cout<<"\n";
 }
 return 0;
}
