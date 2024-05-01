#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5+5;
const int INF=1e9+10;
const ll llINF=1e18+10;
const ll mod=1e9+7;

vector<ll> r(N,-llINF);



ll rod_cut(vector<ll>& p, ll n)
{
    if(r[n] >= 0)
    {
        return r[n];
    }

    ll q = -llINF;
    for(ll i=1;i<=n;i++)
    {
        q = max(q, p[i] + rod_cut(p, n-i));
    }

    r[n] = q;
    return q;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k;
    cin>>n>>k;
    //cout<<n<<" "<<k<<endl;
    vector<ll> v(n+1);
    for(ll i=1;i<=n;i++)
    {
        cin>>v[i];
    }

    //for(ll i=1;i<=n;i++){cout<<v[i]<<" ";} cout<<endl;

    ll s=rod_cut(v,n);
    cout<<s<<endl;
}