#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;
const ll llINF=1e18+10;
const ll mod=1e9+7;

ll a,b,c,d,e,f;


ll fn(ll n, vector<ll>& dp)
{
    if(dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = (fn(n-1,dp) + fn(n-2,dp) + fn(n-3,dp) + fn(n-4,dp) + fn(n-5,dp) + fn(n-6,dp))%10000007;
    return dp[n];
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    
    for(ll i=1;i<=t;i++)
    {
        ll n;
        vector<ll> dp(10000+5,-1);
        cin>>a>>b>>c>>d>>e>>f>>n;
        dp[0]=a;
        dp[1]=b;
        dp[2]=c;
        dp[3]=d;
        dp[4]=e;
        dp[5]=f;
        
        cout<<"Case "<<i<<": "<<fn(n,dp)%10000007<<endl;
    }
}