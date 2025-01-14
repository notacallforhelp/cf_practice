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
*/

/*void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}*/

void solve()
{
    int n; cin>>n;
    string s; cin>>s;

    int ct0=0;
    int ct1=0;

    for(int i=0;i<n;i++)
    {
        if(s[i]=='1') ++ct1;
        if(s[i]=='0') ++ct0;
    }

    if(ct1!=ct0)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> answer;

    int turns = 0;

    int sz = n;

    bool opover = false;

    for(int i=0;i<sz/2;i++)
    {
        int left = i;
        int right = sz-i-1;

        //cout << s[left] <<" " << s[right] << "for idx " << left << " " << right << endl;;
        //cout << s << endl;

        if(s[left]!=s[right])
        {
            //cout << left << " " << right << endl;
            continue;
        }

        if(turns>10)
        {
            break;
        }

        if(s[left]=='1')
        {
            if(turns>=300)
            {
                opover=true;
                break;
            }
            answer.push_back(i);

            string k ="";

            for(int j=0;j<i;j++)
            {
                k.push_back(s[j]);
            }
            k.push_back('0');
            k.push_back('1');

            for(int j=i;j<sz;j++)
            {
                k.push_back(s[j]);
            }
            s=k;
            sz+=2;
            ++turns;
        }
        else if(s[left]=='0')
        {
            //cout << "hi" << endl;
            if(turns>=300)
            {
                opover=true;
                break;
            }
            answer.push_back(sz-i);
            
            string k = "";

            for(int j=0;j<=right;j++)
            {
                k.push_back(s[j]);
            }
            k.push_back('0');
            k.push_back('1');

            for(int j=right+1;j<sz;j++)
            {
                k.push_back(s[j]);
            }
            s=k;
            sz += 2;
            ++turns;
            //cout << k << endl;
        }
    }

    //cout << s << endl;

    bool valid = true;

    for(int i=0;i<sz/2;i++)
    {

        if(s[i]==s[sz-i-1])
        {
            valid=false;
            break;
        }
    }

    if(opover)
    {
        cout << -1 << endl;
        return;
    }

    if(valid)
    {
        cout << answer.size() << endl;

        for(auto &ele:answer)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    //setIO("problemname");

    int t; cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}