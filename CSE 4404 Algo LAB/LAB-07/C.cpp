//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 
//Author: Khalid9029
 
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
const int N=1e5;
const int INF=1e9+10;
const ll llINF=1e18+10;
const ll mod=1e9+7;

vector<ll> count(ll n, ll a, ll b, ll c)
{
    vector<ll> dp(n+1,-llINF);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(i>=a)
            dp[i]=max(dp[i],dp[i-a]+1);
        if(i>=b)
            dp[i]=max(dp[i],dp[i-b]+1);
        if(i>=c)
            dp[i]=max(dp[i],dp[i-c]+1);
    }
    return dp;
}
 
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    vector<ll> ans=count(n,a,b,c);
    cout<<ans[n]<<endl;
}