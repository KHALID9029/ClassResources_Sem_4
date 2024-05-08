//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 
//Author: Khalid Hasan Ador
//ID: 210042102
 
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
const int N=1e5;
const int INF=1e9+10;
const ll llINF=1e18+10;
const ll mod=1e9+7;

ll ways(ll k)
{
    vector<ll> dp(k+1, 0);
    dp[0]=1;

    for(ll i=1; i<=k; i++)
    {
        for(ll x=1;x<7;x++)
        {
            if(i-x>=0)
            {
                dp[i]=(dp[i]+dp[i-x])%mod;
            }
        }
    }
    return dp[k];
}
 
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    cout<<ways(n)<<endl;
}