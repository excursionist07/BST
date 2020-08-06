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

ll FindMin(node *root)
{
 if(root==NULL)
    return -1;
 else if(root->left==NULL)
    return root->data;
 else
    FindMin(root->left);
}

ll FindMax(node *root)
{
  if(root==NULL)
    return -1;
  else if(root->right==NULL)
    return root->data;
  else
    FindMax(root->right);
}

ll FindHeight(node *root)
{
 if(root==NULL)
    return -1; // if counting edges ,if u have to count nodes replace -1 with 0
 else
 {
   ll LH=FindHeight(root->left);
   ll RH=FindHeight(root->right);
   return max(LH,RH)+1;
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
  cout<<FindMin(root)<<endl;
  cout<<FindMax(root)<<endl;
  cout<<FindHeight(root)<<endl;/*O(n)*/
 }
 return 0;
}
