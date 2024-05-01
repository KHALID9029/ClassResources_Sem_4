#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;
const ll llINF=1e18+10;
const ll mod=1e9+7;

ll Cross(vector<ll> &a, ll l, ll m, ll h) 
{  
    ll sum = 0; 
    ll left_sum = INT_MIN; 
    for (ll i = m; i >= l; i--) 
    { 
        sum = sum + a[i]; 
        if (sum > left_sum) 
            left_sum = sum; 
    } 
  
    
    sum = 0; 
    ll right_sum = INT_MIN; 
    for (ll i = m; i <= h; i++) 
    { 
        sum = sum + a[i]; 
        if (sum > right_sum) 
            right_sum = sum; 
    } 

    return max({left_sum + right_sum - a[m], left_sum, right_sum}); 
} 
  

ll msas(vector<ll>&a, ll l, ll h) 
{ 
    if (l > h) 
        return INT_MIN; 
     
    if (l == h) 
        return a[l]; 
  

    ll m = (l + h) / 2; 
  
    return max({msas(a, l, m - 1), msas(a, m + 1, h),Cross(a, l, m, h)}); 
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

    cout<<msas(a,0,n-1)<<endl;
}