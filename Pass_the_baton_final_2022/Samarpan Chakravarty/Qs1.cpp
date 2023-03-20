#include <bits/stdc++.h>
using namespace std;

#define int long long

int fin = 0;
int n = 0;
int h = 0;
int res = 0;

void go(int ht, int dir, int l, int r) {
    if (fin == 1) {
        return;
    } else {
        if (l == r && l == n) {
            fin = 1;
            return;
        }
        if (l == r) {
            res++;
            return;
        }
    }
    int mid = (l + r) / 2;
    int subtree = (1ll<<(h - ht)) - 1;
    if (dir == 0) {
        res++;
        if (mid + 1 <= n && n <= r) {
            go(ht + 1, 1, mid + 1, r);
            if (fin == 0) {
                res += subtree;
            }
        } else {
            res += subtree;
            go(ht + 1, 0, l, mid);
        }
    } else {
        res++;
        if (l <= n && n <= mid) {
            go(ht + 1, 0, l, mid);
            if (fin == 0) {
                res += subtree;
            }
        } else {
            res += subtree;
            go(ht + 1, 1, mid + 1, r);
        }
        
        
    }
}


signed main() {
    cin >> h >> n;
    go(0, 1, 1, (1ll<<h));
    cout << res << endl;
    
    return 0;
}

