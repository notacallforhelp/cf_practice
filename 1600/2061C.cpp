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

/*
FOR SIMULATING ALL CELLS THAT SHARE A WALL WITH CURRENT CELL, GRID IS OF SIZE N*M

int dx[]={-1,0,+1,0};
int dy[]={0,-1,0,+1};

inline bool in(int i,int j){
    return (0<=i&&i<n&&0<=j&&j<m);
}


binary exp 

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

ceil 

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
    // return fact[n]%mod*ifact[n-k]%mod*ifact[k]%mod;
}

ifact[N-1] = pw(fact[N-1],mod-2);
for(int i=N-2;i>=0;i--)
{
    ifact[i]=1ll*ifact[i+1]*(i+1)%mod;
}

void find_divisors()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=i;j<=N;j+=i)
        {
            divisors[j].push_back(i);
        }
    }
}

DFS

vector<vector<int>> adj(n);
vector<bool> visited(n);

void dfs(int current_node) {
	if (visited[current_node]) { return; }
	visited[current_node] = true;

	for (int neighbor : adj[current_node]) { dfs(neighbor); }
}

BFS

for (int i = 0; i < n; i++) {
		// iterate over all connected components in the graph
		if (!visited[i]) {
			queue<int> q;
			q.push(i);
			visited[i] = true;
			while (!q.empty()) {
				int current_node = q.front();
				q.pop();
				for (int neighbor : adj[current_node]) {
					if (!visited[neighbor]) {
						visited[neighbor] = true;
						q.push(neighbor);
					}
				}
			}
		}
	}

SIEVE

void sieve(int n,vector<bool> &prime)
{
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==true)
        {
            for(int p=i*i;p<=n;p+=i)
            {
                prime[p]=false;
            }
        }
    }
}
prime[0]=prime[1]=false;


DSU

const int N = 2e5+10;
int parent[N];int size[N];

void make(int v)
{
    parent[v]=v;
    size[v]=1;
}

int find(int v)
{
    if(v==parent[v]) return v;
    //path compression
    return parent[v] = find(parent[v]);
}

void Union(int a,int b)
{
    a = find(a); b = find(b);
    if(a!=b)
    {
        //union by size
        if(size[a]<size[b]) swap(a,b); 
        parent[b]=a;
        size[a] += size[b];
    }
}

DJIKSTRA

vector<bool> vis(n);
set<pair<int,int>> s;  // {dist,node}
s.insert({0,src})
vector<int> dist(n,INF); dist[src]=0;

while(!s.empty())
{
    auto it = s.begin();
    int v = it->second;
    int d = it->first;
    s.erase(it);

    if(vis[v]) continue;
    vis[v]=1;

    for(auto [child,wt]:adj[v])
    {
        if(!vis[child[ && dist[v]+wt<dist[child])
        {
            //optional
            auto old = s.find({dist[child],child});
            if(old!=s.end()) s.erase(old);

            dist[child]=dist[v]+wt;
            s.insert({dist[child],child});
        }
    }
}

too many modulos then use this

void add_self(int &a,int b)
{
    a += b;
    if(a>=mod) a-=mod;
}

void self_min(int &a,int b)
{
    a = min(a,b);
}

void self_max(int &a,int b)
{
    a = max(a,b);
}

example of iterative dfs
auto dfs = [&](auto&& self, TreeNode* node) -> int {
    if (!node) return 0;
    return 1 + max(self(self, node->left), self(self, node->right));
};
return dfs(dfs, root);

__builtin_clz(a); //returns count of leading zeroes of a, doing 31- that gives first set bit of a 

int get_first_bit(long long n){
	return 63 - __builtin_clzll(n);
}

int get_bit_count(long long n){
	return __builtin_popcountll(n);
}

PROBABILITY / DP Functions

const int MOD = 998244353;

int add(int x, int y) {
   x += y;
   if (x >= MOD) x -= MOD;
   if (x < 0) x += MOD;
   return x;
}
 
int mul(int x, int y) {
  return x * 1LL * y % MOD;
}
 
int binpow(int x, int y) {
  int z = 1;
  while (y) {
    if (y & 1) z = mul(z, x);
    x = mul(x, x);
    y >>= 1;
  }
  return z;
}
 
int divide(int x, int y) {
  return mul(x, binpow(y, MOD - 2));
}

RANDOMIZATION
mt19937 mt(727);  //gets 32 bits integers randomly generated, seed is 727 to produce reproducible behavior
uniform_int_distribution uni(1, 3);  // ={1,2,3}

*/

/*void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}*/


void solve()
{   
    
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