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
    int n, m; cin>>n>>m;

    char A[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>A[i][j];
        }
    }

    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<A[i][j];
        }
        cout << endl;
    }*/

    int min_x = 0;
    int min_y=0;
    int max_x = m-1;
    int max_y = n-1;

    int turns = 0;

    int sz = min(n/2,m/2);

    vector<char> output[sz];

    while(turns<min(n/2,m/2))
    {
        for(int i=min_x;i<=max_x;i++)
        {
            output[turns].push_back(A[min_y][i]);
        }
        for(int i=min_y+1;i<=max_y;i++)
        {
            output[turns].push_back(A[i][max_x]);
        }
        for(int i=max_x-1;i>=min_x;i--)
        {
            output[turns].push_back(A[max_y][i]);
        }
        for(int i=max_y-1;i>=min_y;i--)
        {
            output[turns].push_back(A[i][min_x]);
        }
        output[turns].push_back(output[turns][1]);
        output[turns].push_back(output[turns][2]);
        ++turns;
        ++min_x;
        ++min_y;
        --max_x;
        --max_y;
    }
    int answer=0;
    /*for(auto &ele:output)
    {
        for(auto k:ele)
        {
            cout << k << " ";
        }
        cout << endl;
    }*/
    for(auto &ele:output)
    {
        for(int i=0;i<ele.size();i++)
        {
            if(i+3>=ele.size())
            {
                continue;
            }
            if(ele[i]=='1'&&ele[i+1]=='5'&&ele[i+2]=='4'&&ele[i+3]=='3')
            {
                //cout << i << endl;
                ++answer;
            }
        }
    }
    cout << answer<<endl;
}

int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int t; cin>>t;

    while(t--)
    {
        solve();
    }
}