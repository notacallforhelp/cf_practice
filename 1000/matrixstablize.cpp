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
    int n, m; cin>>n>>m;
    int A[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>A[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            set <int> s;
            if(i-1>=0)
            {
                if(A[i-1][j]<A[i][j])
                {
                    s.insert(A[i-1][j]);
                }
                else
                {
                    continue;
                }
            }
            if(i+1<=n-1)
            {
                if(A[i+1][j]<A[i][j])
                {
                    s.insert(A[i+1][j]);
                }
                else
                {
                    continue;
                }
            }
            if(j-1>=0)
            {
                if(A[i][j-1]<A[i][j])
                {
                    s.insert(A[i][j-1]);
                }
                else
                {
                    continue;
                }
            }
            if(j+1<=m-1)
            {
                if(A[i][j+1]<A[i][j])
                {
                    s.insert(A[i][j+1]);
                }
                else
                {
                    continue;
                }
            }
            if(s.size()>0)
            {
                A[i][j]=*s.rbegin();
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
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