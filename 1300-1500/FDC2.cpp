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
    int n,k,q; cin>>n>>k>>q;
 
    vector<int> points(k+1);
    points[0]=0;
    vector<int> time(k+1);
    time[0]=0;
 
    map<int,int> alreadyknown;
 
    for(int i=1;i<=k;i++)
    {
        cin>>points[i];
    }
    for(int i=1;i<=k;i++)
    {
        cin>>time[i];
    }
    for(int i=0;i<k+1;i++)
    {
        alreadyknown[points[i]]=time[i];
    }
    while(q--)
    {
        int d; cin>>d;
 
        if(d==0)
        {
            cout << 0 << " ";
            continue;
        }
        if(alreadyknown[d]!=0)
        {
            cout << alreadyknown[d] << " ";
            continue;
        }
 
        int low=0;
        int high=k;
        int idxleft=-1; //arb low val
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(points[mid]<d)
            {
                idxleft=max(mid,idxleft);
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        int ans=0;
        ans = time[idxleft] + (d-points[idxleft])*(time[idxleft+1]-time[idxleft])/(points[idxleft+1]-points[idxleft]);
        cout << ans << " ";
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