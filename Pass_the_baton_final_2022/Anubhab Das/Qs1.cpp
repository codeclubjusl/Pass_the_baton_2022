#include <iostream>
using namespace std;
#define ll long long
int main() {
// Anubhab
//     int h;
//     ll n;
//     cin >> h >> n;
//     ll sub_size = 1;
//     for (int i = 0; i < h + 1; ++i) sub_size *= 2;
//     sub_size -= 1;
//     bool even = true;
//     ll cur = 1, lo = 1, hi = sub_size / 2 + 1, ans = 0;
//     ++h;
//     while (h--) {
//         ll mid = (lo + hi) / 2;
//         cout << cur << ": " << lo << " " << hi << " " << mid << " " << sub_size << " " << ans << endl;
//         ++ans;
//         if (n <= mid) {
//             cout << "LEFT\n";
//             cur = cur * 2;
//             if (!even) ans += sub_size / 2;
//             hi = mid;
//         } else {
//             cout << "RIGHT\n";
//             cur = cur * 2 + 1;
//             if (even) ans += sub_size / 2;
//             lo = mid + 1;
//         }
//         even ^= 1;
//         // if (n == mid) break;
//         sub_size /= 2;
//     }
//     --ans;
//     cout << ans << "\n";
    
// Arka
    ll h,n;
    cin>>h>>n;
    
    ll ht=0;
    ll before=0;
    ll ans=0;
    
    char prev='R';
    while(true)
    {
        ll del=h-ht;
        ll down=(1ll<<del);
        ll vertices=2*((1ll<<del)-1);
        
        bool first=false;
        if(before+down/2>=n)
            first=true;
        
        // cout << first << endl;
        
        if(first)
        {
            if(prev=='R')
            {
                ht++;
            }
            else
            {
                ht++;
                ans+=vertices/2;
            }
            prev='L';
        }
        else
        {
            if(prev=='L')
            {
                ht++;
                before+=down/2;
            }
            else
            {
                ht++;
                before+=down/2;
                ans+=vertices/2;
            }
            prev='R';
        }
        ans ++ ;
        
        // cout << ht << " "<< before<<" "<<ans << endl;
        
        if(ht==h && before+1==n)
            break;
    }
    
    cout<<ans;
}

    
