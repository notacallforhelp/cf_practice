#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


typedef long long int ll;
typedef long double ld;

//ordered_sets
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

//struct for range 
struct range
{
    ll l,r,index;
    bool operator < (const range &other) const
    {
        if(l==other.l)
            return r>other.r;
        return l < other.l;
    }
};

/*binary search template

while(hi-low>0)
    {
        ll mid = (low+hi)/2;
        ll products = 0;
        for(int i=0;i<n;i++)
        {
            products += min(mid/A[i],(ll)1e9);
        }
        if(products>=k)
        {
            if(mid<answer)
            {
                answer = mid;
            }
            hi = mid;
        }
        else
        {
            low = mid+1;
        }
    }

*/


void solve()
{

    int a, b; cin>>a>>b;

    pair<int,int> king;
    cin>>king.first>>king.second;

    pair<int,int> queen;
    cin>>queen.first>>queen.second;

    set<pair<int,int>> kingpos;
    set<pair<int,int>> queenpos;

    ll output = 0;

    kingpos.insert({king.first+b,king.second+a});
    kingpos.insert({king.first+a,king.second+b});
    kingpos.insert({king.first-b,king.second+a});
    kingpos.insert({king.first+a,king.second-b});
    kingpos.insert({king.first-a,king.second+b});
    kingpos.insert({king.first-a,king.second-b});
    kingpos.insert({king.first-b,king.second-a});
    kingpos.insert({king.first+b,king.second-a});

    queenpos.insert({queen.first+b,queen.second+a});
    queenpos.insert({queen.first+a,queen.second+b});
    queenpos.insert({queen.first-b,queen.second+a});
    queenpos.insert({queen.first+a,queen.second-b});
    queenpos.insert({queen.first-a,queen.second+b});
    queenpos.insert({queen.first-a,queen.second-b});
    queenpos.insert({queen.first-b,queen.second-a});
    queenpos.insert({queen.first+b,queen.second-a});

     /*for(auto ele:kingpos)
        {
            cout << ele.first << " " << ele.second << endl;
        }
        cout << endl;
        for(auto ele:queenpos)
        {
            cout << ele.first << " " << ele.second << endl;
        }*/

    for(auto &ele:queenpos)
    {
        if(kingpos.count(ele))
        {
            ++output;
        }
    }

    cout << output << endl;


}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int t; cin>>t;

    while(t--)
    {
        solve();
    }
}