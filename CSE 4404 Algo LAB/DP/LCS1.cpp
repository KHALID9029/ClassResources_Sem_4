//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 
//Author: Khalid9029
 
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
const int N=1e5;
const int INF=1e9+10;
const ll llINF=1e18+10;
const ll mod=1e9+7;

ll LCS(string x, string y, ll i, ll j, string& ans)
{
    vector<vector<ll>> dp(i+1, vector<ll>(j+1, 0));

    for(ll k=1; k<=i; k++)
    {
        for(ll l=1;l<=j;l++)
        {
            if(x[k-1]==y[l-1])
            {
                dp[k][l]=1+dp[k-1][l-1];
            }
            else
            {
                dp[k][l]=max(dp[k-1][l], dp[k][l-1]);
            }
        }
    }

    string lcs="";
    ll k=i, l=j;
    while(k>0 && l>0)
    {
        if(x[k-1]==y[l-1])
        {
            lcs+=x[k-1];
            k--;
            l--;
        }
        else
        {
            if(dp[k-1][l]>dp[k][l-1])
            {
                k--;
            }
            else
            {
                l--;
            }
        }
    }
    //cout<<lcs<<"\n";
    reverse(lcs.begin(), lcs.end());
    ans=lcs;
    return dp[i][j];
}
 
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string x, y;
    cin>>x>>y;
    ll n=x.size();
    ll m=y.size();

    string ans="";
    LCS(x, y, n, m, ans);
    //cout<<LCS(x, y, n, m, ans)<<"\n";
    cout<<ans<<"\n";
}