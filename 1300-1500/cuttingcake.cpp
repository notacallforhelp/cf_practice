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
    ll n,m,v; cin>>n>>m>>v;

    vector<ll> A(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
    }

    vector<ll> pf(n+1);

    for(int i=1;i<=n;i++)
    {
        pf[i]=pf[i-1]+A[i];
    }

    int ct = 0;

    vector<ll> pfpos; pfpos.push_back(0);

    ll sum=0;

    for(int i=1;i<=n;i++)
    {
        if(pfpos.size()==m+1)
        {
            break;
        }
        sum += A[i];
        if(sum>=v)
        {
            pfpos.push_back(i);
            sum=0;
        }
    }

    if(pfpos.size()!=m+1)
    {
        cout << -1 << endl; return;
    }

    vector<ll> sfpos; sfpos.push_back(n+1);

    sum=0;

    for(int i=n;i>=1;i--)
    {
        if(sfpos.size()==m+1)
        {
            break;
        }
        sum+= A[i];
        if(sum>=v)
        {
            sfpos.push_back(i);
            sum=0;
        }
    }
    reverse(sfpos.begin(),sfpos.end());
    ll ans = 0;

    for(int i=0;i<m+1;i++)
    {
        //cout << pf[sfpos[i]-1]-pf[pfpos[i]] << endl;
        ans = max(ans,pf[sfpos[i]-1]-pf[pfpos[i]]);
    }
    cout << ans << endl;
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