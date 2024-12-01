#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


#define int ll

using ll = long long;

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

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N= 2e5+10;

const ll inf = 1e15+10;

int A[N];int n;
vector<int> g[N];

bool dfs(int vertex,int value)
{
    if(g[vertex].size()==0)
    {
        if(A[vertex]<value) return false;
    }
    if(!vertex)
    {
        value = max(0ll,value-A[vertex]);
    }
    else
    {
        if(A[vertex]<value)
        {
            value = min(inf,value + value-A[vertex]);
        }
    }

    for(auto c:g[vertex])
    {
        if(!dfs(c,value)) return false;
    }
    return true;
}


void solve()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    for(int i=1;i<n;i++)
    {
        int par; cin>>par;
        --par;
        g[par].push_back(i);
    }

    int low=0;
    int high=inf;

    int ans =0;

    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(dfs(0,mid))
        {
            ans = mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    cout << ans << endl;

    for(int i=0;i<n;i++)
    {
        g[i].clear();
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    //setIO("problemname");

    int t; cin>>t;

    while(t--)
    {
        solve();
    }
}