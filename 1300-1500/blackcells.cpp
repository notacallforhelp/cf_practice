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
    int n; cin>>n;
    vector<ll> A(n); for(auto &i:A) cin>>i;

    if(n%2==0)
    {
        sort(A.begin(),A.end());

        ll ans = 0;

        for(int i=0;i<n;i=i+2)
        {
            ans = max(ans,A[i+1]-A[i]);
        }

        cout << ans << endl;
    }
    else
    {
        sort(A.begin(),A.end());

        ll ans = LLONG_MAX;

        if(n==1)
        {
            cout << 1 << endl; return;
        }

        for(int i=0;i<n;i++)
        {
            vector<ll> temp;

            for(int j=0;j<n;j++)
            {
                if(j==i)
                {
                    continue;
                }
                temp.push_back(A[j]);
            }

            ll tempans=0;

            for(int i=0;i<n-1;i=i+2)
            {
                tempans = max(tempans,temp[i+1]-temp[i]);
            }
            ans = min(ans,tempans);
        }
        cout << ans << endl;
    }
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