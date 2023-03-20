#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int power(long long int n,int k,int mod)
{
    if(n==1)
        return 1;
    if(n==0)
        return 0;
    if(k==0)
        return 1;
    if(k%2==0)
    {
        n=((n%mod)*(n%mod))%mod;
        k/=2;
        return power(n,k,mod);
    }
    else
    {
        return ((n%mod)*(power(n,k-1,mod)%mod))%mod;
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int mod=1e9+7;
    long long int n;
    cin>>n;
    int even=ceil(n/2.0);
    int odd=(n/2);
    cout<<((power(4,odd,mod)%mod)*(power(5,even,mod)%mod))%mod;
    
    return 0;
}

