#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


#define int long long
typedef long long ll;
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

ll ceil2(ll a, ll b) {
    if (a == 0) return 0;
    return (a - 1)/b + 1;
}

COMBINATORICS TEMPLATE 
const int N = 2e5 + 5, mod = 1e9 + 7;
int64_t fact[N];
int64_t pw(int64_t a, int64_t b) {
	int64_t r = 1;
	while(b > 0) {
		if(b & 1) r = (r * a) % mod;
		b /= 2;
		a = (a * a) % mod; 
	}
	return r;
}
int64_t C(int64_t n, int64_t k) {
	if(n < k) return 0LL;
	return (fact[n] * pw((fact[n - k] * fact[k]) % mod, mod - 2)) % mod;
}
*/

/*void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}*/

const int mod = 1e9+7;

void solve()
{
    int n; cin>>n;
    vector<int> cost(n+1); for(int i=1;i<=n;i++) cin>>cost[i];

    int m; cin>>m;

    vector<vector<int>> adj(n+1);

    for(int i=0;i<m;i++)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<vector<int>> og = adj;

    deque<int> st;
    vector<bool> vis(n+1);

    vector<int> temp;

    auto dfs = [&](auto &&self,int v)-> void {
        if(vis[v]) return;
        vis[v]=1;

        for(auto &ele:adj[v])
        {
            self(self,ele);
        }

        if(st.size()==n) temp.push_back(v);
        if(st.size()<n) st.push_front(v);
    };

    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        dfs(dfs,i);
    }

    for(int i=1;i<=n;i++)
    {
        vis[i]=0;
        adj[i].clear();
    }

    for(int i=1;i<=n;i++)
    {
        for(auto &ele:og[i])
        {
            adj[ele].push_back(i);
        }
    }

    int ways = 1;
    int price = 0;

    for(int i=0;i<st.size();i++)
    {
        if(vis[st[i]]) continue;

        temp.clear();
        dfs(dfs,st[i]);

        int mn = 1e15;

        for(auto &ele:temp)
        {
            mn = min(mn,cost[ele]);
        }

        int ct = 0;

        for(auto &ele:temp)
        {
            if(cost[ele]==mn) ++ct;
        }

        price += mn;
        ways = (ways*ct)%mod;
    }

    cout << price << " " << ways << "\n";

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    //setIO("problemname");

    int t=1; //cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}