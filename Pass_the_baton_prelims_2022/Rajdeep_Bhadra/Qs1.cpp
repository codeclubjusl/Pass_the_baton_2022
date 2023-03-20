#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solve(int n,int k)
{
    if(n==1)
        return 1;
    return (solve(n-1,k)+k-1)%n+1;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,k;
    cin>>n>>k;
    cout<<solve(n,k);
    
    return 0;
}
