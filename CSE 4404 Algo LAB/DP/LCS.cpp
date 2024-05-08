//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 
//Author: Khalid9029
 
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
const int N=1e5;
const int INF=1e9+10;
const ll llINF=1e18+10;
const ll mod=1e9+7;

ll dp[1000][1000];

ll LCS(string s1, string s2, ll i, ll j)
{
    if(i==0 || j==0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];
    
    if(s1[i]==s2[j]) return dp[i][j]=1+LCS(s1, s2, i-1, j-1);
    else return dp[i][j]=max(LCS(s1, s2, i-1, j), LCS(s1, s2, i, j-1));
}
 
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin>>s1>>s2;
    memset(dp, -1, sizeof(dp));
    cout<<LCS(s1, s2, s1.size(), s2.size());
}