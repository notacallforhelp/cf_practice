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

ll binpow(ll a,ll b)
{
    if(b==0)
    {
        return 1;
    }
    if(b%2)
    {
        return (a*binpow(a,b-1))%mod;
    }
    return binpow((a*a)%mod,b/2);
}

*/

void solve()
{
    string A = "abcdefghijklmnopqrstuvwxyz";
    int n; cin>>n;
    string s; cin>>s;

    if(n%2==0)
    {
        map<char,int> even;
        map<char,int> odd;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                ++odd[s[i]];
            }
            else
            {
                ++even[s[i]];
            }
        }
        int cost = n;
        int evencost=0;
        for(auto &ele:even)
        {
            evencost = max(evencost,ele.second);
        }
        int oddcost=0;
        for(auto &ele:odd)
        {
            oddcost = max(oddcost,ele.second);
        }
        cost = cost-evencost-oddcost;
        cout << cost << endl;
    }
    else
    {
        map<char,int> evenleft;
        map<char,int> oddleft;
        map<char,int> evenright;
        map<char,int> oddright;

        for(int i=0;i<n;i++)
        {
            if(i%2==1)
            {
                ++oddright[s[i]];
            }
            else
            {
                ++evenright[s[i]];
            }
        }

        int cost = INT_MAX;


        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                --evenright[s[i]];
            }
            else
            {
                if((i-1)%2==0)
                {
                    ++oddleft[s[i-1]];
                }
                else
                {
                    ++evenleft[s[i-1]];
                }

                if(i%2==0)
                {
                    --evenright[s[i]];
                }
                else
                {
                    --oddright[s[i]];
                }
            }
            int oddmx = 0;
            int evenmx = 0;
            for(int i=0;i<26;i++)
            {
                oddmx = max(oddmx,oddleft[A[i]]+oddright[A[i]]);
                evenmx = max(evenmx,evenright[A[i]]+evenleft[A[i]]);
            }
            /*for(auto ele:oddleft)
            {
                oddmx = max(oddmx,ele.second);
            }
            for(auto ele:oddright)
            {
                oddmx = max(oddmx,ele.second);
            }
            int evenmx=0;
            for(auto ele:evenleft)
            {
                evenmx = max(evenmx,ele.second);
            }
            for(auto ele:evenright)
            {
                evenmx = max(evenmx,ele.second);
            }
            //cout << oddmx << " " << evenmx << endl;*/
            int temp = (n)-oddmx-evenmx;
            cost = min(cost,temp);
        }
        cout << cost << endl;
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