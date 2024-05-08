//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 
//Author: Khalid9029
 
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
const int N=1e5;
const int INF=1e9+10;
const ll llINF=1e18+10;
const ll mod=1e9+7;
 
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    vector<string> g(n);
    for(int i=0; i<n; i++)
    {
        cin>>g[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    for(ll i=0;i<n;i++)
    {
        if(g[0][i]=='*')
        {
            break;
        }
        dp[0][i]=1;
    }

    for(ll j=0;j<n;j++)
    {
        if(g[j][0]=='*')
        {
            break;
        }
        dp[j][0]=1;
    }

    for(ll i=1;i<n;i++)
    {
        for(ll j=1;j<n;j++)
        {
            if(g[i][j]=='*')
            {
                continue;
            }
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    cout<<dp[n-1][n-1]<<"\n";
}