#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        vector<ll> v(n);
        vector<ll> pre(n+1,0),cnt1(n+1,0);

        for(ll i=0;i<n;i++)
        {
            cin>>v[i];
            pre[i+1]=pre[i]+v[i];
            cnt1[i+1]=cnt1[i]+(v[i]==1);
        }

        while(q--)
        {
            ll l,r;
            cin>>l>>r;
            ll cur1=cnt1[r]-cnt1[l-1];
            ll curs=pre[r]-pre[l-1];

            if(r!=l && ((r-l+1)+cur1) <= curs)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
    }
}