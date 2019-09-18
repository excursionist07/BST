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

vector<int>v;
vector<int>v1;
void printleaves(Node *root)
{
  if(root==NULL)
    return;
  if(root->left==NULL && root->right==NULL)
  {
     v.push_back(root->data);
     return;
  }

  if(root->left)
     printleaves(root->left);
  if(root->right)
     printleaves(root->right);
}
void in(Node *root)
{
  if(root==NULL)
    return;
  in(root->left);
  v1.push_back(root->data);
  in(root->right);
}

bool isDeadEnd(Node *root)
{
  v.clear();
  v1.clear();
  printleaves(root);
  in(root);
  int ff=0;
  for(int i=0;i<v.size();i++)
  {
     if((v[i]==1 && (binary_search(v1.begin(),v1.end(),v[i]+1))|| (binary_search(v1.begin(),v1.end(),v[i]-1) && binary_search(v1.begin(),v1.end(),v[i]+1))))
     {

       ff=1;
       return 1;

     }
  }
  if(ff==0)
    return 0;

}
