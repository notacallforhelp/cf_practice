#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


#define int long long
typedef long long ll;
typedef long double ld;

void solve()
{   
   int n,m,T; cin>>n>>m>>T;

   vector<int> A(n+1); for(int i=1;i<=n;i++) cin>>A[i];
   vector<int> B(m+1); for(int i=1;i<=m;i++) cin>>B[i];
   vector<int> pf(n+1);
   for(int i=1;i<=n;i++)
   {
        pf[i]=pf[i-1]+A[i];
   }

   int output = 0;

   for(int i=1;i<=n;i++)
   {
        auto it = lower_bound(B.begin()+1,B.end(),i);
        int best = 0;

        if(it!=B.begin()+1)
        {
            int left = *(it-1);
            int timewasted = max(pf[i-1]-pf[left-1],0ll);
            if(timewasted<=T)
            {
                int timeleft = max(0ll,T-timewasted);
                int laps = (i-left)+timeleft/A[i];
                best = max(best,laps);
            }
        }

        if(it!=B.end())
        {
            int right = *it;
            int timewasted = max(pf[right]-pf[i],0ll);
            if(timewasted<=T)
            {
                int timeleft = max(0ll,T-timewasted);
                int laps = (right-i)+timeleft/A[i];
                best = max(best,laps);
            }
        }

        output = max(best,output);
   }

   cout << output << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    //setIO("problemname");

    int t=1; //cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}