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
 
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    vector<ll> v(n),s(n);
    bool flag=true;

    cin>>v[0];
    s[0]=v[0];

    for(ll i=1; i<n; i++)
    {
        cin>>v[i];
        s[i]=v[i];

        if(v[i]<v[i-1]) flag=false;
    }

    ll dec=0, ac=0;
    ll start,end;

    if(flag)
    {
        cout<<"yes"<<endl;
        cout<<1<<" "<<1<<endl;
        return 0;
    }

    for(ll i=1; i<n; i++)
    {
        //cout<<"Here\n";

        if(v[i]<v[i-1] && dec==0)
        {
            //cout<<"Here\n";
            start=i;
            while(v[i]<v[i-1])
            {
                i++;
            }
            end=i;
            dec=1;
        }
    }

    sort(s.begin(),s.end());
    //for(auto e:s) cout<<e<<" "; cout<<endl;

    reverse(v.begin()+start-1,v.begin()+end);
    //for(auto e:v) cout<<e<<" "; cout<<endl;


    if(v==s)
    {
        cout<<"yes"<<endl;
        cout<<start<<" "<<end<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
}