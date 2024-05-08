//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 
//Author: Khalid9029
 
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
const int N=1e5;
const int INF=1e9+10;
const ll llINF=1e18+10;
const ll mod=1e9+7;

ll LIS(vector<ll>& a)
{
    ll n=a.size();
    vector<ll> dp(n, 1);
    vector<ll> parent(n, -1);
    ll mx=1, idx=0;
    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<i;j++)
        {
            if(a[i]>a[j] && dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
                parent[i]=j;
            }
        }
        if(dp[i]>mx)
        {
            mx=dp[i];
            idx=i;
        }
    }
    vector<ll> ans;
    while(idx!=-1)
    {
        ans.push_back(a[idx]);
        idx=parent[idx];
    }
    reverse(ans.begin(), ans.end());
    for(auto i: ans)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
    return mx;
}



ll LISlog(vector<ll>& a)
{
    vector<ll>ans;
    ll n=a.size();

    for(ll i=0;i<n;i++)
    {
        auto it=lower_bound(ans.begin(), ans.end(), a[i]);
        if(it==ans.end())
        {
            ans.push_back(a[i]);
        }
        else
        {
            *it=a[i];
        }
    }
    for(auto i: ans)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
    return ans.size();
}
 
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<LISlog(a)<<"\n";
}