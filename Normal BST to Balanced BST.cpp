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
void in1(Node* root)
{
 if(root==NULL)
   return;
 in1(root->left);
 vec.push_back(root->data);
 in1(root->right);
}

Node *GetNewNode(int x)
{
  Node *temp=new Node();
  temp->data=x;
  temp->left=temp->right=NULL;
  return temp;

}
Node *BalancedBST(vector<int>vec,int start,int end)
{
 if(start>end)
   return NULL;
  int mid=(start+end)/2;
  Node *root=GetNewNode(vec[mid]);

  root->left=BalancedBST(vec,start,mid-1);
  root->right=BalancedBST(vec,mid+1,end);

  return root;
}
Node* buildBalancedTree(Node* root)
{
  vec.clear();
  in1(root);

  root=BalancedBST(vec,0,vec.size()-1);
  return root;

}
