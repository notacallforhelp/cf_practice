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

const int N = 3e5+10;
const int mod = 998244353;
int n;
int a[N];

void add(int &a,int b)
{
    a += b;
    if(a>=mod) a-= mod;
}

int sum(int a,int b)
{
    a += b;
    if(a>=mod) a-= mod;
    if(a<0) a+= mod;

    return a;
}

int mul(int a,int b)
{
    return (a*1LL*b)%mod;
}

void solve()
{
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];

    int res = 0;
    for(int b=0;b<30;b++)
    {
        int cur=0;
        vector<int> cnt(2);
        vector<int> sumofL(2);

        cnt[0]=1;
        int x = 0;
        for(int i=0;i<n;i++)
        {
            x^=((a[i]>>b)&1);
            int sumofR = mul(cnt[x^1],i+1);
            add(cur,sum(sumofR,-sumofL[x^1]));

            ++cnt[x];
            add(sumofL[x],i+1);
        }

        add(res,mul(1<<b,cur));
    }
    cout << res << "\n";
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