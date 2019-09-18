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

vector<int>vec;

void in1(Node *root1)
{
  if(root1==NULL)
    return;
  in1(root1->left);
  vec.push_back(root1->data);
  in1(root1->right);
}

void in2(Node *root2)
{
  if(root2==NULL)
    return;
  in1(root2->left);
  vec.push_back(root2->data);
  in1(root2->right);
}

void merge(Node *root1, Node *root2)
{
  vec.clear();
  if(root1==NULL && root2==NULL)
    return;
  in1(root1);
  in2(root2);
  sort(vec.begin(),vec.end());
  for(int i=0;i<vec.size();i++)
  {
    cout<<vec[i]<<" ";
  }
}
