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

ll binpow(ll a,ll b)
{
    if(b==0)
    {
        return 1;
    }
    if(b%2)
    {
        return (a*binpow(a,b-1))%mod;
    }
    return binpow((a*a)%mod,b/2);
}

*/

void solve()
{
    int n, m, k; cin>>n>>m>>k;
    int w; cin>>w;

    vector<int> heights(w);

    for(int i=0;i<w;i++)
    {
        cin>>heights[i];
    }

    vector<ll> weights;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int ub_x = min(i,n-k);
            int lb_x = max(0,i-k+1);
            int ub_y = min(j,m-k);
            int lb_y = max(0,j-k+1);

            weights.push_back((ub_x-lb_x+1)*(ub_y-lb_y+1));
        }
    }
    sort(weights.rbegin(),weights.rend());
    sort(heights.rbegin(),heights.rend());

    ll output = 0;

    for(int i=0;i<w;i++)
    {
        output += weights[i]*heights[i];
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