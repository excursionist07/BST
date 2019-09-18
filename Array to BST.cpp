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

struct Node
{
  ll data;
  Node *left;
  Node *right;
};
Node *GetNewNode(ll x)
{
 Node *temp=new Node();
 temp->data=x;
 temp->left=temp->right=NULL;
 return temp;
}
Node *BalancedBST(ll a[],ll start,ll end)
{
  if(start>end)
    return NULL;
  ll mid=(start+end)/2;
  Node *root=GetNewNode(a[mid]);

  root->left=BalancedBST(a,start,mid-1);
  root->right=BalancedBST(a,mid+1,end);

  return root;

}
void pre(Node *root)
{
  if(root==NULL)
    return;
  cout<<root->data<<" ";
  pre(root->left);
  pre(root->right);
}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll n;
  cin>>n;
  ll a[n];
  f(n)
  {
    cin>>a[i];
  }
  Node *temp=BalancedBST(a,0,n-1);
  pre(temp);
  cout<<"\n";

 }
 return 0;
}
