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
    map<int,set<pair<int,char>>> M;   //prefix balance, {index*-1,char}
    vector<int> pf(s.length());
    pf[0]=0;
    for(int i=1;i<s.length();i++)
    {
        if(s[i-1]=='(')
        {
            pf[i]=pf[i-1]+1;
        }
        else
        {
            pf[i]=pf[i-1]-1;
        }
    }
    for(int i=0;i<s.length();i++)
    {

        M[pf[i]].insert({i*-1,s[i]});
    }
    for(auto &ele:M)
    {
        for(auto &k:ele.second)
        {
            cout << k.second;
        }
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int t=1;

    while(t--)
    {
        solve();
    }
}