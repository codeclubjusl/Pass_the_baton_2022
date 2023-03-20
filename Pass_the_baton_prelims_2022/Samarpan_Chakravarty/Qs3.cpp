#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    
    int n=0;
    cin>>n;
    string s;
    cin>>s;
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (string("aeiou").find(s[i]) == string::npos) {
            ;
        } else {
            int l = i + 1;
            int r = n - l + 1;
            res = res + (l * r);
        }
    }
    
    cout << res;
    

    
    
    return 0;
}

