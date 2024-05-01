#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;
const ll llINF=1e18+10;
const ll mod=1e9+7;

vector<ll> rod_cut(vector<ll>& p, ll n, vector<ll>& path)
{
    vector<ll> ans(n+1);
    ans[0]=0;

    for(ll j=1;j<=n;j++)
    {
        ll q=-llINF;
        for(ll i=1;i<=j;i++)
        {
            if(p[i]+ans[j-i]>q)
            {
                q=p[i]+ans[j-i];
                path[j]=i;
            }
        }
        ans[j]=q;
    }
    return ans;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    vector<ll> v(n+1);
    for(ll i=1;i<=n;i++)
    {
        cin>>v[i];
    }

    vector<ll> path(n+1);
    vector<ll> s=rod_cut(v,n,path);

    cout<<"Maximum Profit: "<<s[n]<<endl;
    cout<<"Path: ";
    ll i=n;
    while(i>0)
    {
        cout<<path[i]<<" ";
        i-=path[i];
    }
}