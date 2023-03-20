#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int h, n, i;
    
    cin >> h >> n;
    n--;
    int a[51];
    for(i = 0; i < h; i++)
    {
        a[i] = (n >> i) & 1;
        // cout << a[i] << "\n";
    }
    
    int v = 0;
    // for(i = 0; i < (1 << h); i++)
    // {
    //     c[i] = v;
    //     v = v ^ 1;
    // }
    
    int ans = 1;
    for(i = 0; i < h; i++)
    {
        // cout << a[h - 1 - i] << " " << v << " " << ans << "\n";
        if(a[h - 1 - i] != v)
        {
            ans += (1 << (h - i + 1)) / 2;
            
            
            
        }
        else
        {v = v ^ 1;
         ans++;}
    }
    ans--;
    cout << ans << "\n";
    return 0;
}

