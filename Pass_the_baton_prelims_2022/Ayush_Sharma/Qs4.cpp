#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace chrono;
// using namespace __gnu_pbds;
 
#define int long long
#define ld long double
#define endl "\n"
#define pi  3.141592653589
#define INF 1e18
#define vi  vector<int>
#define vvi vector<vector<int>>
#define mi map<int,int>
#define mpi map<pair<int,int>,int>
#define vpi vector<pair<int,int>>
#define pr  pair<int,int>
#define mp  make_pair
#define triplet pair<int,pair<int,int>>
#define ff first
#define ss second
#define pb push_back
#define MAX INT_MAX
#define MIN INT_MIN
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define read(x) int x; cin>>x
#define pD(x,y) cout<<fixed<<setprecision(y)<<x
#define google(tno) cout<<"Case #"<<tno<<": "
#define pqb priority_queue<int>
#define pqs priority_queue<int,vi,greater<int> >
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mod 998244353
#define LMAX 9223372036854775807
const int MOD=1e9+7;
const int GN=1e7+10;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
vector<bool> sieve(GN,1);
int dsieve[GN];
/*---------------------------------------------------------------------------------------------------------------------------*/
bool isPrime(int n){for(int i=2;i*i<=n;i++){if(n%i==0)return false;}return true;}
void primeSieve(){sieve[0] = sieve[1] = false;for (int i = 2; i*i<= GN; i++) {if (sieve[i]) {for (int j = i*i; j <= GN; j += i)sieve[j] = false;}}}
void divSieve(){for(int i=1;i*i<=GN;i++){for(int j=i;j<=GN;j=j+i){++dsieve[j];}}}
vector<vector<int>> matProd(vector<vector<int>> A,vector<vector<int>> B,int size){int sum=0;vector<vector<int>> C(size);
for(int i=0;i<size;i++){for(int j=0;j<size;j++){for(int k=0;k<size;k++){sum+=A[i][k]*B[k][j];}C[i].pb(sum);sum=0;}}return C;}
vector<vector<int>> matExp(vector<vector<int>> A,int n,int size){
if(n==0){for(int i=0;i<size;i++){for(int j=0;j<size;j++){if(i==j) A[i][j]=1; else A[i][j]=0;}}return A;}
if(n==1)return A;
vector<vector<int>> temp=matExp(A,n/2,size);if(n%2==0)return matProd(temp,temp,size);else return matProd(A,matProd(temp,temp,size),size);}
vector<int> prefixSum(vector<int> &A){vector<int> res(A.size());res[0]=A[0];for(int i=1;i<A.size();i++){res[i]=A[i]+res[i-1];} return res;}
void printMatrix(vector<vector<int>> &A,int n,int m){for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<A[i][j]<<" ";}cout<<endl;}}
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
int binexp(int x,int n){int a=x;int prod=1;while(n){if(n%2==1)prod=prod*a;a=a*a;n=n/2;    }return prod;}
map<int,int> primeFactorisation(int n){map<int,int> mpp;for(int i=2;i*i<=n;i++){if(n%i==0){int cnt=0;while(n%i==0){++cnt;n=n/i;}mpp[i]=cnt;}}if(n>1)mpp[n]=1;return mpp;}
vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {vector<int> temp;int ptr1=0;int ptr2=0;int c=0;while(true){if(ptr1==m || ptr2==n)break;if(nums1[ptr1]<nums2[ptr2]){temp.push_back(nums1[ptr1]);ptr1++;}else{temp.push_back(nums2[ptr2]);ptr2++;}c++;}for(int i=ptr1;i<m;i++){temp.push_back(nums1[i]);c++;}for(int i=ptr2;i<n;i++){temp.push_back(nums2[i]);c++;}return temp;}
int modexp(int a, int b, int m) {a %= m;int res = 1;while (b > 0) {if (b & 1)res = res * a % m;a = a * a % m;b >>= 1;}return res;}
 
/*--------------------------------------------------------------------------------------------------------------------------*/
 

int func(int ind,int n,vvi &arr,vi &dp){
    if(ind>=n)
        return 0;
    if(dp[ind]!=-1)return dp[ind];
    int pick=arr[ind][0]+func(ind+arr[ind][1]+1,n,arr,dp);
    int nonpick=func(ind+1,n,arr,dp);
    
    return dp[ind]=max(pick,nonpick);
}
 
void solve()
{
    int n;
    cin>>n;
    
    vvi arr;
    for(int i=0;i<n;i++){
        int p,b;
        cin>>p>>b;
        arr.pb({p,b});
    }
    vi dp(n+1,-1);
    cout<<func(0,n,arr,dp)<<endl;
}
int32_t main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    auto start1 = high_resolution_clock::now();
    solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cerr << "Time : " << duration . count() / 1000 << endl;
 
return 0;
}
