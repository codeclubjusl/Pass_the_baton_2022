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

#define int long long
const int MOD = 1e9 + 7;

template < typename Number , Number m >
class modNum{
private:
  Number val;

public:
  friend ostream& operator << (ostream& os, modNum const &num) { return os << num.val; }
  friend istream& operator >> (istream& is, modNum &num) { is >> num.val; num.val %= m; return is; }

  modNum () : val(0) {}
  modNum (Number N) : val(N % m) {}

  Number get() const { return val; }

  Number modInverse(Number b, Number mod){
    Number x, y;
    Number g = gcdExtended(b, mod, &x, &y);
    if (g != 1)
        return -1;
    return (x % mod + mod) % mod;
  }
  Number modDivide(Number a, Number b, Number mod){
    a = a % mod;
    Number inv = modInverse(b, mod);
    if (inv == -1)
     return -1;
    else{
      Number c = (inv * a) % mod ;
      return c;
    }
  }
  Number gcdExtended(Number a, Number b, Number *x, Number *y){
    if (a == 0){
        *x = 0, *y = 1;
        return b;
    }
    Number x1, y1;
    Number gcd = gcdExtended(b % a , a , &x1 , &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
  }
  Number modPow(Number b, Number e , Number mod) {
    Number res = 1;
    while (e > 0) {
      if(e & 1) res = (res * b) % mod;
      b = (b * b) % mod;
      e >>= 1;
    }
    return res;
  }

  modNum operator = (modNum b){ val = b.get(); return b; }
  modNum operator + (modNum b){ modNum t = (val + b.get()) % m; return t; }
  modNum operator * (modNum b){ modNum t = (val * b.get()) % m; return t; }
  modNum operator / (modNum b){ modNum t = modDivide(val , b.get() , m); return t; }
  modNum operator - (modNum b){ modNum t = ((val - b.get()) % m + m) % m; return t; }
  modNum operator ^ (modNum b){ modNum t = modPow(val , b.get() , m); return t; }
  modNum operator += (modNum b){ val = (val + b.get()) % m; return val; }
  modNum operator *= (modNum b){ val = (val * b.get()) % m; return val; }
  modNum operator /= (modNum b){ val = modDivide(val , b.get() , m); return val; }
  modNum operator -= (modNum b){ val = ((val - b.get()) % m + m) % m; return val; }
  modNum operator ^= (modNum b){ val = modPow(val , b.get() , m); return val; }

  bool operator < (modNum b){ return val < b.get(); }
  bool operator > (modNum b){ return val > b.get(); }
  bool operator == (modNum b){ return val == b.get(); }
  bool operator <= (modNum b){ return val <= b.get(); }
  bool operator >= (modNum b){ return val >= b.get(); }
};
typedef modNum < int , MOD > mint;

#define INF INT_MAX
#define all(x) x.begin() , x.end()

void solve(){
    int n; cin >> n;
    mint ans = (mint(5) ^ ((n + 1) / 2)) * (mint(4) ^ (n / 2));
    cout << ans << "\n";
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

