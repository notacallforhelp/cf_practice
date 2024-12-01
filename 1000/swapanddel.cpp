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
    string s; cin>>s;
    int cnt0=0;
    int cnt1=0;

    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
        {
            ++cnt1;
        }
        else
        {
            ++cnt0;
        }
    }
    string t="";
    for(int i=0;i<s.length();i++)
    {
        char c = s[i];
        if(c=='1')
        {
            if(cnt0>0)
            {
                --cnt0;
                t.push_back('0');
            }
            else
            {
                break;
            }
        }
        if(c=='0')
        {
            if(cnt1>0)
            {
                --cnt1;
                t.push_back('1');
            }
            else
            {
                break;
            }
        }
    }
    cout << s.length()-t.length() << endl;

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