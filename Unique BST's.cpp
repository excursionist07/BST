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

ll catalan(ll n)
{
 ll dp[n+1]={0};
 dp[0]=1;
 dp[1]=1;
 for(ll i=2;i<=n;i++)
 {
  for(ll j=1;j<=i;j++)
  {
     dp[i]=dp[i]+(dp[i-j]*dp[j-1]);
  }
 }
 cout<<dp[n]<<endl;

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
    catalan(n);
  }
  return 0;

}
