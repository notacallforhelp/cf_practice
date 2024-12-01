#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


#define int long long int
typedef long double ld;

//ordered_sets
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

//struct for range 
struct range
{
    int l,r,index;
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

int quad(int a, int b)
{
    if (a > 0 && b > 0)
        return 1;
    else if (a <= 0 && b >= 0)
        return 2;
    else if (a < 0 && b < 0)
        return 3;
    else
        return 4;
}

void solve()
{
    int x1,y1,x2,y2,x3,y3; cin>>x1>>y1>>x2>>y2>>x3>>y3;
    x2 -= x1;
    y2 -= y1;
    x3 -=x1;
    y3-=y1;
    int q1 = quad(x2,y2);
    int q2 = quad(x3,y3);
    if((q1==1&&q2==3)||(q1==3&&q2==1)||(q1==2&&q2==4)||(q1==4&&q2==2))
    {
        cout << 1 << endl;
    }
    else if(q1==q2)
    {
        cout << min(abs(x2),abs(x3))+min(abs(y2),abs(y3))+1 << endl;
    }
    else if(y2*y3>=0&&x2*x3<=0)
    {
        cout << min(abs(y2),abs(y3))+1 << endl;
    }
    else
    {
        cout << min(abs(x2),abs(x3))+1 << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int t; cin>>t;

    while(t--)
    {
        solve();
    }
    return 0;
}