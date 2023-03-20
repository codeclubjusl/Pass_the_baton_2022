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
#define debug(x...)

#define INF INT_MAX
#define all(x) x.begin() , x.end()

//#define int long long

void solve() {
    int n; cin >> n;
    vector < int > p (n) , b (n);
    for (int i = 0 ; i < n ; i++) cin >> p[i] >> b[i];
    debug(p , b);
    vector < int > dp (n);
    for (int i = n - 1 ; i >= 0 ; i--) {
        if (i + b[i] + 1 < n) dp[i] = max( p[i] + dp[i + b[i] + 1] , dp[i + 1] );
        else dp[i] = max( p[i] , dp[i + 1] );
    }
    debug(dp);
    cout << dp[0] << "\n";
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
