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
    for(int i=2;i*i<=n;i++)
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

*/

/*void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}*/

void solve()
{
    int n; cin >>n;
    vector<int> A(n); for(auto &i:A) cin>>i;

    vector<pair<int,int>> pr(n);

    for(int i=0;i<n;i++)
    {
        pr[i]={A[i],i};
    }
    sort(pr.begin(),pr.end());
    map<int,int> M;
    for(int i=0;i<n;i++)
    {
        M[pr[i].first]++;
        if(pr[i].first<i+1||M[pr[i].first]>2)
        {
            cout <<"NO" << endl;
            return;
        }
    }
    reverse(pr.begin(),pr.end());
    vector<int> q(n);
    vector<int> p(n);
    set<int> pused; set<int> qused;

    for(int i=0;i<n;i++)
    {
        if(pused.count(pr[i].first)==0)
        {
            p[pr[i].second]=pr[i].first;
            pused.insert(pr[i].first);
        }
        else
        {
            q[pr[i].second]=pr[i].first;
            qused.insert(pr[i].first);
        }
    }
    deque<int> punused;
    deque<int> qunused;

    for(int i=1;i<=n;i++)
    {
        if(pused.count(i)==0)
        {
            punused.push_back(i);
        }
        if(qused.count(i)==0)
        {
            qunused.push_back(i);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(p[pr[i].second]!=0)
        {
            q[pr[i].second]=qunused.back();
            qunused.pop_back();
        }
        else if(q[pr[i].second]!=0)
        {
            p[pr[i].second]=punused.back();
            punused.pop_back();
        }
    }
    cout << "YES" << endl;
    for(auto &ele:p)
    {
        cout << ele << " ";
    }
    cout << endl;
    for(auto &ele:q)
    {
        cout << ele << " ";
    }
    cout << endl;
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