#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

using uint = unsigned;

const uint T = 2000;
const uint R = 200000;

uint Ord[R+5];
uint Nxt(uint p,uint o){
    uint x = p/T, y = p%T;
    

    return x*T+y;
}

bool G[2][T*T];
uint Ans[2];

void solve()
{   
   
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    for(uint i=2,tp=0;i<T&&tp<R;i++)
    {
        if(i%3==2)
        {
            for(uint x=1;x<i&&tp<R;x+=3) Ord[tp++]=x*T+i-x;
        }
        else if(!(i%3))
        {
            for(uint x =1;x<=i-2&&tp<R;x++)
            {
                if(x%3==1) Ord[tp++]=x*T+i-x;
                else if(x%3==2) Ord[tp++]=x*T+i-x-2,Ord[tp++]=x*T+i-x;
            }
            Ord[tp++]=(i-1)*T+1;
        }
    }

    int t; cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}