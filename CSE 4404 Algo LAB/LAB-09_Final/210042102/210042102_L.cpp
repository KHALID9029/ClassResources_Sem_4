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

void top_sort(vector<ll> adj[],vector<ll> &indegree,ll n)
{
    set<ll> q;
    vector<ll> ans;
    for(ll i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            q.insert(i);
        }
    }

    //cout<<q.size()<<endl;

    while(!q.empty())
    {
        ll u=*q.begin();
        q.erase(q.begin());
        //cout<<u<<" ";
        //cout<<endl;
        ans.push_back(u);
        for(auto it:adj[u])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.insert(it);
            }
        }
    }

    //cout<<"Result: ";
    if(ans.size()!=n)
    {
        cout<<"Sandro fails"<<endl;
        return;
    }
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin>>n>>m;
    vector<ll> adj[n+1];
    vector<ll> indegree(n+1,0);
    for(ll i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    top_sort(adj,indegree,n);
}