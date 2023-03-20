#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    
    map<int,int>mp,mp2;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        mp[A[i]]++;
        mp2[mp[A[i]]]++;
        int disElements = mp.size();
        //cout<<mp[A[i]]<<" "<<mp2[mp[A[i]]]<<" "<<disElements<<'\n';
        if(i!=n-1&&i+1==mp[A[i]]*mp2[mp[A[i]]])
        {
            ans = min(n,i+2);
        }
        
        if(i==(mp[A[i]])*mp2[mp[A[i]]])
        {
            ans = i+1;
        }
        
        
        
    }
    cout<<ans;
    return 0;
}

