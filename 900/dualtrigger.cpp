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
    string s; cin>>s;

    int onect=0;

    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            ++onect;
        }
    }
    if(onect==0)
    {
        cout << "YES" << endl;
    }
    else if(onect%2!=0)
    {
        cout << "NO" << endl;
    }
    else if(onect==2)
    {
        int pos =-2;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                if(pos+1==i)
                {
                    cout << "NO" << endl;
                    return;
                }
                pos = i;
            }
        }
        cout << "YES" << endl;
    }
    else
    {
        cout << "YES" << endl;
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