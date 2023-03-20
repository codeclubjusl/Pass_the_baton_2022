#include <bits/stdc++.h>
using namespace std;

#define int long long int

signed main() {
    int n; cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    map<int, int> cnt, icnt;
    icnt[0] = n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int c = cnt[a[i]];
        cnt[a[i]]++;
        icnt[c]--;
        icnt[c + 1]++;
        
        if (icnt[c] == 0) {
            icnt.erase(c);
        }
        
        // for (auto p : icnt) {
        //     cout << p.first << ' ' << p.second << endl;
        // }
        // cout << endl;
        
        if (icnt.size() > 3) {
            continue;
        } else {
            vector<int> cnts;
            for (auto p : icnt) {
                if (p.first == 0) {
                    continue;
                }
                cnts.push_back(p.second);
            }
            if (cnts[0] == 1 || cnts[1] == 1) {
                res = max(res, i + 1);
            }
        }
    }
    
    cout << res << endl;
    
    return 0;
}

