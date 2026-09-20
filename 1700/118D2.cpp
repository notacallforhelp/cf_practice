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

const int mod = 1e8;
int dp[102][102][2][11];

void solve()
{
    int n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;
    int K[2] = {k1,k2};

    dp[1][0][0][1]=1;
    dp[0][1][1][1]=1;

    for(int a=0;a<=n1;a++)
    {
        for(int b=0;b<=n2;b++)
        {
            for(int last=0;last<2;last++)
            {
                for(int s=1;s<=K[last];s++)
                {
                    int cur = dp[a][b][last][s];

                    if(last==0)
                    {
                        if(s<k1&&a<n1)
                            dp[a+1][b][0][s+1] = (dp[a+1][b][0][s+1]+cur)%mod;
                        
                        if(b<n2)
                            dp[a][b+1][1][1] = (dp[a][b+1][1][1]+cur)%mod;
                    }
                    else
                    {
                        if(s<k2&&b<n2)
                            dp[a][b+1][1][s+1] = (dp[a][b+1][1][s+1]+cur)%mod;
                        
                        if(a<n1)
                            dp[a+1][b][0][1] = (dp[a+1][b][0][1]+cur)%mod;
                    }
                }
            }
        }
    }

    int output = 0;

    for(int last=0;last<2;last++)
    {
        for(int s=1;s<=K[last];s++)
        {
            output = (output+dp[n1][n2][last][s])%mod;
        }
    }

    cout << output << "\n";
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