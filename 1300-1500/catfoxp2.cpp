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

bool check(vector<int> &A,int bigOR,int mid)
{
    vector<int> bitSET(32);

    for(int i=31;i>=0;i--)
    {
        for(int j=0;j<mid;j++)
        {
            if((1ll<<i)&A[j])
            {
                ++bitSET[i];
            }
        }
    }
    int bigOR2=0;
    for(int i=0;i<32;i++)
    {
        if(bitSET[i])
        {
            bigOR2 += (1ll<<i);
        }
    }
    if(bigOR2!=bigOR)
    {
        return false;
    }

    for(int i=1;i+mid-1<A.size();i++)
    {
        int x = A[i-1];
        for(int j=31;j>=0;j--)
        {
            if((1ll<<j)&x)
            {
                --bitSET[j];
                if(bitSET[j]==0)
                {
                    bigOR2 -= (1ll<<j);
                }
            }
        }
        int y = A[i+mid-1];
        for(int j=31;j>=0;j--)
        {
            if((1ll<<j)&y)
            {
                ++bitSET[j];
                if(bitSET[j]==1)
                {
                    bigOR2 += (1ll<<j);
                }
            }
        }
        if(bigOR!=bigOR2)
        {
            return false;
        }
    }
    return true;
}


void solve()
{
    int n; cin>>n;
    int bigOR=0;
    vector<int> A(n); for(auto &i:A)cin>>i;
    for(int i=0;i<n;i++)
    {
        bigOR |= A[i];
    }

    int low=1;
    int high = n;
    int ans = n+1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;

        if(check(A,bigOR,mid))
        {
            ans = min(ans,mid);
            high=mid-1;
        }
        else
        {
            low=mid+1;
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