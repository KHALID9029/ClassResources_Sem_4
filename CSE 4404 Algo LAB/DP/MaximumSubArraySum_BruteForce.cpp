#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;
const ll llINF=1e18+10;
const ll mod=1e9+7;


ll maxSubArraySum(vector<ll> a)
{
    ll n=a.size();
    ll maxSum=INT_MIN;
    for(ll i=0;i<n;i++)
    {
        for(ll j=i;j<n;j++)
        {
            ll sum=0;
            for(ll k=i;k<=j;k++)
            {
                sum+=a[k];
            }
            maxSum=max(maxSum,sum);
        }
    }
    return maxSum;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<maxSubArraySum(a)<<endl;
}