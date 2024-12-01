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
    int n; cin>>n;
    vector<int> A(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    int idx = -1;
    for(int i=1;i<n;i++)
    {
        if(A[i]<A[i-1])
        {
            idx = i;
            break;
        }
    }
    if(idx==-1)
    {
        cout << "Yes" << endl;
        return;
    }

    for(int i=idx+1;i<n;i++)
    {
        if(A[i]<A[i-1])
        {
            cout << "No" << endl;
            return;
        }
    }
    if(A[0]<A[n-1])
    {
        cout << "No" << endl;
        return;
    }
    for(int i=1;i<idx;i++)
    {
        if(A[i]<A[i-1])
        {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
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