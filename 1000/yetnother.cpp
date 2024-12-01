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
    stack<int> caps;
    stack<int> smalls;

    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='b')
        {
            if(!smalls.empty())
            {
                smalls.pop();
            }
        }
        else if(s[i]=='B')
        {
            if(!caps.empty())
            {
                caps.pop();
            }
        }
        else if(s[i]>='a'&&s[i]<='z')
        {
            smalls.push(i);
        }
        else if(s[i]>='A'&&s[i]<='Z')
        {
            caps.push(i);
        }
    }
    string o = "";
    while(!caps.empty()&&!smalls.empty())
    {
        int k = caps.top();
        int m = smalls.top();
        if(k>m)
        {
            o.push_back(s[k]);
            caps.pop();
        }
        else
        {
            o.push_back(s[m]);
            smalls.pop();
        }
    }
    while(!caps.empty())
    {
        o.push_back(s[caps.top()]);
        caps.pop();
    }
    while(!smalls.empty())
    {
        o.push_back(s[smalls.top()]);
        smalls.pop();
    }
    reverse(o.begin(),o.end());
    cout << o << endl;
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