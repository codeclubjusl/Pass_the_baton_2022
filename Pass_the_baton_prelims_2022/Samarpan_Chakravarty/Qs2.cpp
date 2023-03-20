#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long

int fexp(int a, int b) {
    if (b == 0) {
        return 1;
    } else if (b % 2) {
        return (a * fexp(a, b - 1)) % mod;
    }
    int z = fexp(a, b / 2);
    return (z * z) % mod;
}

signed main()
{
    int n; cin>>n;
    
    int res = 1;
    
    int no = 0,ne = 0;
    
    if(n%2) {
        ne = n/2 + 1;
        no = n/2;
    }
    else
    {
        no = n/2;
        ne = n/2;
    }
    
    //ne--;
    
    //res = (fexp(5, ne) * 4) % mod;
    res = (fexp(5, ne)) % mod;
    res = (res * fexp(4, no)) % mod;
    
    //if (res == 4) res++;
    cout << res;
    
    return 0;
}
