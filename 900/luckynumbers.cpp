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

int eval(int a)
{
    int mn = a%10;
    int mx = a%10;
    while(a)
    {
        mn = min(a%10,mn);
        mx = max(a%10,mx);
        a=a/10;
    }
    return mx-mn;
}

void solve()
{
    int l,r; cin>>l>>r;

    int check = r;
    int answer = r;
    while(check>=l)
    {
        if(eval(check)>eval(answer))
        {
            answer = check;
        }
        if(eval(answer)==9)
        {
            break;
        }
        --check;
    }
    cout << answer << endl;
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