#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int helper(vector<vector<int>>&v, int n, vector<int>&dp, int i){
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1) return dp[i];
    return dp[i] = max(v[i][0]+helper(v,n,dp,i+v[i][1]+1), helper(v,n,dp,i+1));
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i = 0; i<n;++i){
        vector<int> tmp(2);
        cin>>tmp[0]>>tmp[1];
        v.push_back(tmp);
    }
    vector<int> dp(n,-1);
    cout<<helper(v,n,dp,0);
    return 0;
}
