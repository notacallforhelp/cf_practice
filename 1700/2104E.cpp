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
   int n,k; cin>>n>>k;
   string s; cin>>s;

   vector<int> d(n+1,0);
   vector<vector<int>> nxt(n+2,vector<int>(k,n));

   for(int i=n-1;i>=0;i--)
   {
        nxt[i]=nxt[i+1];
        int mx = *max_element(nxt[i].begin(),nxt[i].end());
        d[i] = 1+d[mx];
        nxt[i][s[i]-'a']=i;
   }

   int q; cin>>q;
   while(q--)
   {
        string t; cin>>t;
        int pos = -1;
        for(char c:t)
        {
            pos = nxt[pos+1][c-'a'];
        }
        cout << d[pos] << "\n";
   }
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