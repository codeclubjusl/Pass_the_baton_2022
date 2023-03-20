#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
//#define debug(x...)

#define INF INT_MAX
#define all(x) x.begin() , x.end()

//#define int long long

void solve() {
    int n , k; cin >> n >> k;
    vector < int > v (n); for (int i = 0 ; i < n ; i++) v[i] = i + 1;
    int curr = 0;
    while (v.size() > 1) {
        debug(v , curr);
        v.erase(v.begin() + (curr + k - 1) % v.size());
        curr = (curr + k - 1) % (v.size() + 1);
    }
    cout << v[0] << "\n";
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int tt = 1; //cin >> tt;
  for (int i = 1 ; i <= tt ; i++) {
    //cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
