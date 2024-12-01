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
    int n, k; cin>>n>>k;
    vector<int> A(n);
    map<int,set<int>> M;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        M[i%k].insert(A[i]);
    }
    int cnt = 0;

    for(auto &ele:M)
    {
        int a = ele.first;
        for(int m=a+1;m<=n;m=m+k)
        {
            if((ele.second).find(m)==(ele.second).end())
            {
                ++cnt;
            }
        }
    }
    
    if(cnt==0)
    {
        cout << 0 << endl;
    }
    else if(cnt==2)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << -1 << endl;
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