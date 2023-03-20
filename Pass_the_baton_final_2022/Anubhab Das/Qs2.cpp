//FcJywM
#include<bits/stdc++.h>
#define pi 3.141592653589793238
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
 
#define mt make_tuple
#define printclock cerr<<"Time : "<<1000*(long double)clock()/(long double)CLOCKS_PER_SEC<<"ms\n";
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll B) { return (unsigned ll)rng() % B;}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll _T = 1;
    
    // cin >> _T;
    while (_T--) {
        ll n;
        cin >> n;
        multiset<ll> s;
        map<ll,ll> cnt, ccnt;
        vector<ll> v(n);
        
        ll ans = 1;
        ll mx = 0, mn = n;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            ll p = cnt[v[i]];
            if(p) {
                s.erase(s.find(p));
                ccnt[p]--;
            }
            
            s.insert(p + 1);
            cnt[v[i]]++;
            ccnt[p + 1]++;
            
            if(i == 0) continue;
            mx = *prev(s.end());       
            mn = *s.begin();
            ll sz = s.size();
            // cout << i << " : " << mx << " " << mn << " " << sz << " " << ccnt[mn] << " " << ccnt[mx] << endl;
            
            if(ccnt[mx] == 1 && ccnt[mn] == sz - 1 && mn + 1 == mx) {
                ans = i + 1;
            }
            if(mn == 1 && ccnt[mn] == 1 && ccnt[mx] == sz - 1) {
                ans = i + 1;
            }
            if(mn == 1 && mn == mx && ccnt[mn] == sz) {
                ans = i + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
