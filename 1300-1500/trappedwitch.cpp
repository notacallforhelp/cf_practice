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

void solve()
{
    int n,m; cin>>n>>m;

    string c[n+1];

    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        c[i]="-"+c[i];
    }
    
    vector<pair<int,int>> jda[n+2][m+2];


    //the reversed graph parent child reln

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(c[i][j]=='U') jda[i-1][j].push_back({i,j});
            if(c[i][j]=='D') jda[i+1][j].push_back({i,j});
            if(c[i][j]=='L') jda[i][j-1].push_back({i,j});
            if(c[i][j]=='R') jda[i][j+1].push_back({i,j});
        }
    }

    int vis[n+2][m+2]={};

    //theyre visiting all the very edges where theres no real string or anything
    //okay so the plan is a bfs, they inserted all the cells which can give an exit

    queue<pair<int,int>> q;
    for(int j=0;j<=m+1;j++) vis[0][j]=1,q.push({0,j});  //first row
    for(int i=1;i<=n+1;i++) vis[i][0]=1,q.push({i,0});  //first col
    for(int j=1;j<=m+1;j++) vis[n+1][j]=1,q.push({n+1,j});  //last row
    for(int i=1;i<=n;i++) vis[i][m+1]=1,q.push({i,m+1});  //last col

    while(q.size()){
        auto [i,j]=q.front();
        q.pop();
        for(auto[a,b]:jda[i][j])
        {
            if(vis[a][b]==0)
            {
                vis[a][b]=1;
                q.push({a,b});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(c[i][j] == '?' and
            vis[i-1][j] and vis[i][j+1] and vis[i+1][j] and vis[i][j-1]) vis[i][j] = 1;
        }
    }
    int ans = n*m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(vis[i][j]==1)
            {
                ans -=1;
            }
        }
    }
    cout << ans << endl;
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

    return 0;
}