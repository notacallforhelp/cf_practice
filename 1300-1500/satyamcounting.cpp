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

FOR SIMULATING ALL CELLS THAT SHARE A WALL WITH CURRENT CELL, GRID IS OF SIZE N*M

int dx[]={-1,0,+1,0};
int dy[]={0,-1,0,+1};

inline bool in(int i,int j){
    return (0<=i&&i<n&&0<=j&&j<m);
}

*/


void solve()
{
    ll n; cin>>n;

    vector<pair<ll,ll>> A(n);

    for(int i=0;i<n;i++)
    {
        ll x,y; cin>>x>>y;
        A[i]={x,y};
    }
    sort(A.begin(),A.end());
    ll ct = 0;

    for(int i=0;i<n-1;i++)
    {
        if(A[i].first==A[i+1].first)
        {
            ++ct;
        }
    }

    set<ll> y0;
    set<ll> y1;

    ll ct2 = 0;

    for(int i=0;i<n;i++)
    {
        if(A[i].second==0)
        {
            y0.insert(A[i].first);
        }
        else
        {
            y1.insert(A[i].first);
        }
    }

    /*for(auto ele:y0)
    {
        cout << ele << " ";
    }
    cout << endl;

    for(auto ele:y1)
    {
        cout << ele << " ";
    }
    cout << endl;*/

    for(auto ele:y0)
    {
        if(y1.count(ele-1)&&y1.count(ele+1))
        {
            ++ct2;
        }
    }

    for(auto ele:y1)
    {
        if(y0.count(ele-1)&&y0.count(ele+1))
        {
            ++ct2;
        }
    }
    cout << ct*(n-2) +ct2 << endl;
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