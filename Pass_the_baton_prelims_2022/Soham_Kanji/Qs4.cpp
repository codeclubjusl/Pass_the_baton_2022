#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 998244353;
ll maxn = 1e5+1;
void setMod(ll m) {
    mod = m;
}
void setMaxn(ll n) {
    maxn = n;
}
/**********************GCD********************/
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}
/**********************Mod Addition********************/
ll mod_add(ll a, ll b) {
    a = a % mod; 
    b = b % mod;
    return (((a + b) % mod) + mod) % mod;
}
/**********************Mod Multiplication********************/
ll mod_mul(ll a, ll b) {
    a = a % mod; 
    b = b % mod; 
    return (((a * b) % mod) + mod) % mod;
}
/**********************Modulo Inverse********************/
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}

/**********************Calculate Factorials********************/
ll *fact;
void calFact() {
    fact = new ll[maxn];
    fact[0] = 1;
    fact[1] = 1;
    for(ll i=2; i<maxn; i++) fact[i] = mod_mul(fact[i-1], i);
}
/**********************Find nCr********************/
ll ncr(ll n, ll r) {
    ll ans = fact[n];
    ans = mod_mul(ans, inv(fact[n-r]));
    ans = mod_mul(ans, inv(fact[r]));
    return ans;
}
/*********************check if power of 2********************/
bool isPowerOfTwo(ll n)
{
   if(n==0)
   return false;
 
   return (ceil(log2(n)) == floor(log2(n)));
}
/**********************check ith bit********************/
bool isKthBitSet(ll n, ll k)
{
    if (n & (1 << (k - 1))) return true;
    return false;
}
/**********************Binary Exponentiation********************/
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
/**********************Disjoint Set Union********************/
ll *parent, *rank_arr;
void initialize(ll n) {
    parent = new ll[n];
    rank_arr = new ll[n];
    for(ll i=0; i<n; i++) {
        parent[i]=i;
        rank_arr[i]=0;
    }
}
ll find(ll x) {
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}
void merge(ll x, ll y) {
    ll xp = find(x), yp = find(y);
    if(rank_arr[xp]<rank_arr[yp]) {
        parent[xp] = yp;
    } else if(rank_arr[xp]>rank_arr[yp]) parent[yp] = xp;
    else {
        parent[yp]=xp;
        rank_arr[xp]++;
    }
}
/******************************************Prime Numbers******************************************************/
vector<ll> printPrimes(ll n) {
    vector<ll> prime(n+1, true);
    prime[1] = false;
    for(ll i=2; i<=n; i++) {
        if(prime[i]) {
            for(ll j=i*i; j<=n; j+=i) prime[j] = false;
        }
    }
    return prime;
}
ll dp[100001];
ll solve(ll i, vector<vector<ll>> &v) {
    if(dp[i]!=-1) return dp[i];
    ll n = v.size();
    if(i==n) return dp[i] = 0;
    ll ans = solve(i+1, v);
    ans = max(ans, v[i][0]+solve(min(i+v[i][1]+1,n), v));
    return dp[i] = ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<vector<ll>> v(n, vector<ll>(2));
    for(ll i=0; i<n; i++) {
        cin>>v[i][0];
        cin>>v[i][1];
    }
    for(ll i=0; i<=1e5; i++) dp[i] = -1;
    cout << solve(0, v) << "\n";
}


