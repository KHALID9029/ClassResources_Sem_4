#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;

        vector<ll> a(n), x(n);

        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }

        for(ll i=0;i<n;i++)
        {
            cin>>x[i];
        }

        vector<ll> pos(n+1,0);

        for(ll i=0;i<n;i++)
        {
            pos[abs(x[i])]+=a[i];
        }

        ll rem=0;
        bool flag=true;

        for(ll i=1;i<=n;i++)
        {
            rem+=k-pos[i];

            flag&=(rem>=0);
        }

        cout<<(flag?"YES":"NO")<<endl;
    }
}