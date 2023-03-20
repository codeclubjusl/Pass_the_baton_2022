#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    
    int n=0;
    cin>>n;
    
    int a[n][2];
    for(int i = 0; i < n; i++)
        cin>> a[i][0] >> a[i][1];
    
    int dp[n];
    for (int i = n - 1; i >= 0; i--) {
        int dp1 = 0;
        if (i + 1 < n) {
            dp1 = dp[i + 1];
        }
        int dp2 = 0;
        if (i + a[i][1] + 1 < n) {
            dp2 = dp[i + a[i][1] + 1];
        }
        dp[i] = max(dp1, a[i][0] + dp2);
        // cout << i << ' ' << dp[i] << endl;
    }
    
    cout << dp[0];
    
    return 0;
}

