//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 
//Author: Khalid9029
 
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
const int N=1e5;
const int INF=1e9+10;
const ll llINF=1e18+10;
const ll mod=1e9+7;

ll knapsack(ll n, ll w, vector<ll> &wt, vector<ll> &val)
{
    ll dp[n+1][w+1];
    for(ll i=0; i<=n; i++)
    {
        for(ll j=0; j<=w; j++)
        {
            if(i==0 || j==0) dp[i][j]=0;
            else if(wt[i-1]<=j) dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][w];
}
 
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll w,n;
    cin>>w>>n;
    vector<ll> b(n),wt(n);
    for(ll i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(ll i=0;i<n;i++)
    {
        cin>>wt[i];
    }


    ll ans=knapsack(n,w,wt,b);
    cout<<ans<<endl;
}