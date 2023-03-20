#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <limits>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807
#define INF 2000000000
#define PI acos(-1.0)
#define EPS 1e-9
#define LL long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define setzero(a) memset(a,0,sizeof(a))
#define setdp(a) memset(a,-1,sizeof(a))

using namespace std;

vector<LL> anc;
LL sum[51];

int main()
{
    ios_base::sync_with_stdio(0);
    int h;
    LL n;
    cin >> h >> n;
    sum[0] = 1;
    for(int i=1;i<51;i++)
        sum[i] = sum[i-1] + (1LL << i);
    n+=sum[h-1];
    LL x = n;
    anc.push_back(x);
    while(x != 1)
    {
        x = x / 2;
        anc.push_back(x);
    }
    LL res = 0;
    LL node = 1;
    bool choice = false;
    while(node != n)
    {
        vector<LL> ance;
        for(int i=0;i<h;i++)
        {
            ance.push_back(node);
            if(!choice)
                node = node * 2;
            else node = node * 2 + 1;
            choice = !choice;
        }
        if(n == node)
        {
            res+=h;
            break;
        }
        ance.push_back(node);
        reverse(ance.begin(), ance.end());
        for(int i=1;i<=h;i++)
        {
            if(anc[i] == ance[i])
            {
                res+=sum[i - 1] + h - i + 1;
                h = i - 1, node = ance[i - 1];
                if(node == ance[i] * 2)
                    node = ance[i] * 2 + 1, choice = 0;
                else node = ance[i] * 2, choice = 1;
                break;
            }
        }
    }
    cout << res;
    return 0;
}
