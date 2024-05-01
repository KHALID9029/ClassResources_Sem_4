#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 300043;
 
int t;
int n, m;
int a[N];
long long sum[N];
int cnt1[N];
 
int main() {
    ios_base::sync_with_stdio(false);
    
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        cin >> n >> m;
        memset(sum, 0, sizeof(sum[0]) * (n + 5));
        memset(cnt1, 0, sizeof(cnt1[0]) * (n + 5));
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum[i + 1] = sum[i] + a[i];
            cnt1[i + 1] = cnt1[i] + (a[i] == 1);
        }
        
        for (int i = 0; i < m; ++i) {
            int l, r;
            cin >> l >> r;
            --l;
            int cur_cnt1 = cnt1[r] - cnt1[l];
            long long cur_sum = sum[r] - sum[l];

            cout<<cur_cnt1<<" "<<cur_sum<<endl;
            cout<<r-l<<endl;
            
            if((r - l) + cur_cnt1 <= cur_sum && r - l > 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}