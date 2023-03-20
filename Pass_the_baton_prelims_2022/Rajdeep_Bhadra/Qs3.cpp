#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int n;
    cin>>n;
    string s;
    cin>>s;
    int mod=1e9+7;
    long long int ans=0;
    for(long long int i=0;i<n;i++)
    {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
        {
            ans+=((i+1)*(n-i));
        }
    }
    
    cout<<ans;
    
    return 0;
}
