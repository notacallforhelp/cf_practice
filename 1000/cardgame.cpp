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

int game(int first,int second,int third, int fourth)
{
    int suneetscore=0;
    int slavicscore=0;
    if(first>second)
    {
        ++suneetscore;
    }
    else if(first<second)
    {
        ++slavicscore;
    }

    if(third>fourth)
    {
        ++suneetscore;
    }
    else if(third<fourth)
    {
        ++slavicscore;
    }

    if(suneetscore>slavicscore)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void solve()
{
    int a1,a2,b1,b2; cin>>a1>>a2>>b1>>b2;
    int sunnetmin = min(a1,a2);
    int sunnetmax = max(a1,a2);
    int slavicmin = min(b1,b2);
    int slavicmax = max(b1,b2);
    if(sunnetmin>slavicmax)
    {
        cout << 4 << endl;
        return;
    }
    else if(sunnetmax<slavicmin)
    {
        cout << 0 << endl;
        return;
    }

    int output = 0;
    output += game(a1,b1,a2,b2);
    output += game(a2,b1,a1,b2);
    output += game(a1,b2,a2,b1);
    output += game(a2,b2,a1,b1);

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