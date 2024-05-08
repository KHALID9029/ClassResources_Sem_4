//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 
//Author: Khalid9029
 
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
const int N=1e5;
const int INF=1e9+10;
const ll llINF=1e18+10;
const ll mod=1e9+7;

ll is_possible1(ll k, vector<ll>& coins) //one coin any number of times
{
    vector<ll> dp(k+1, 0);
    dp[0]=1;
    for(ll i=1; i<=k; i++)
    {
        for(auto x:coins)
        {
            if(i-x>=0)
            {
                dp[i]=(dp[i]+dp[i-x])%mod;
            }
        }
    }
    return dp[k];
}


vector<vector<ll>> dp(1001, vector<ll>(1001, -1));

ll is_possible2(ll k, ll i, vector<ll>& coins) //one coin one time
{
    if(k==0) return 1;
    if(k<0 || i==0) return 0;
    if(dp[k][i]!=-1) return dp[k][i];

    ll ans=0;
    for(ll j=0; j<i; j++)
    {
        dp[k][i]=(dp[k][i]+is_possible2(k-coins[j], j-1, coins)+ is_possible2(k,j-1,coins))%mod;
    }
    return dp[k][i];
}
 
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}