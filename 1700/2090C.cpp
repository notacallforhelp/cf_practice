#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


#define int long long
typedef long long ll;
typedef long double ld;

vector<pair<int,int>> prs;
const int N = 3e5+10;
vector<bool> vis(N);

void solve()
{   
   int n; cin>>n;
   int curr_first = 1;
   int x = 1; int y = 1;
   vector<pair<int,int>> output;
   vector<int> t(n); 
   for(auto &ele:t) cin>>ele;

   int ptr = 0;

   vector<int> used;

   auto cmp = [&](pair<int,int> a,pair<int,int> b){
        int sumA = a.first+a.second;
        int sumB = b.first+b.second;
        if(a.first%3==2&&a.second%3==2) sumA +=2;
        if(b.first%3==2&&b.second%3==2) sumB +=2;
        if(sumA!=sumB) return sumA<sumB;
        if(a.first!=b.first) return a.first<b.first;
        return a.second<b.second;

    };

   for(int i=0;i<n;i++)
   {
        if(t[i]==0)
        {
            output.push_back({x,y});
            int idx = lower_bound(prs.begin(),prs.end(),output.back(),cmp)-prs.begin();
            while(vis[idx])
            {
                x += 3;
                y -= 3;
                if(y<0)
                {   
                    ++curr_first;
                    x = 1;
                    y = 1 + (curr_first-1)*3;
                }
                output[output.size()-1] = {x,y};
                idx = lower_bound(prs.begin(),prs.end(),output.back(),cmp)-prs.begin();
            }
            vis[idx]=1;
            used.push_back(idx);
        }
        else
        {
            while(vis[ptr]!=0)
            {
                ++ptr;
            }
            output.push_back(prs[ptr]);
            vis[ptr]=1;
            used.push_back(ptr);
        }
   }



   for(auto &[u,v]:output)
   {
        cout << u << " " << v << "\n";
   }

   for(auto &ele:used) vis[ele]=0;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    for(int i=1;i<=316;i++)
    {
        int x = 1;int y = 1 + (i-1)*3;
        for(int j=1;j<=i;j++)
        {
            prs.push_back({x,y});
            prs.push_back({x+1,y});
            prs.push_back({x,y+1});
            prs.push_back({x+1,y+1});

            x += 3;
            y -= 3;
        }
    }

    auto cmp = [&](pair<int,int> a,pair<int,int> b){
        int sumA = a.first+a.second;
        int sumB = b.first+b.second;
        if(a.first%3==2&&a.second%3==2) sumA +=2;
        if(b.first%3==2&&b.second%3==2) sumB +=2;
        if(sumA!=sumB) return sumA<sumB;
        if(a.first!=b.first) return a.first<b.first;
        return a.second<b.second;

    };

    sort(prs.begin(),prs.end(),cmp);

    int t; cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}