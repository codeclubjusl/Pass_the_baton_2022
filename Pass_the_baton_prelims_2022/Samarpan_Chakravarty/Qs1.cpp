#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k; cin >> n >> k;
    set<int> a;
    for (int i = 0; i < n; i++) {
        a.insert(i);
    }
    
    int curr = 0;
    while (a.size() > 1) {
        auto it = a.find(curr);
        for (int i = 0; i < k - 1; i++) {
            it++;
            if (it == a.end()) {
                it = a.begin();
            }
        }
        int next = *it;
        it++;
        if (it == a.end()) {
            it = a.begin();
        }
        a.erase(next);
        curr = *it;
    }
    
    cout << (*a.begin()) + 1;
    
    return 0;
}
