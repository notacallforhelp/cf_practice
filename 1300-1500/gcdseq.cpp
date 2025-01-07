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
    int n; cin>>n;
    vector<int> A(n); for(auto &ele:A)cin>>ele;

    vector<int> B(n);

    for(int i=1;i<n;i++)
    {
        B[i]=__gcd(A[i],A[i-1]);
    }
    int idx=-1;
    for(int i=1;i<n-1;i++)
    {
        if(B[i]>B[i+1])
        {
            idx=i;
            break;
        }
    }
    if(idx==-1)
    {
        cout << "YES\n";
        return;
    }

    vector<int> c1;
    vector<int> c2;
    vector<int> c3;

    for(int i=0;i<n;i++)
    {
        if(i!=idx-1)
        {
            c1.push_back(A[i]);
        }
        if(i!=idx)
        {
            c2.push_back(A[i]);
        }
        if(i!=idx+1)
        {
            c3.push_back(A[i]);
        }
    }
    vector<int> b1;
    vector<int> b2;
    vector<int> b3;
    for(int i=1;i<c1.size();i++)
    {
        b1.push_back(__gcd(c1[i],c1[i-1]));
    }
    for(int i=1;i<c2.size();i++)
    {
        b2.push_back(__gcd(c2[i],c2[i-1]));
    }
    for(int i=1;i<c3.size();i++)
    {
        b3.push_back(__gcd(c3[i],c3[i-1]));
    }
    bool ok1=true;
    bool ok2=true;
    bool ok3=true;
    for(int i=1;i<b1.size();i++)
    {
        if(b1[i]<b1[i-1])
        {
            ok1=false;
        }
        if(b2[i]<b2[i-1])
        {
            ok2=false;
        }
        if(b3[i]<b3[i-1])
        {
            ok3=false;
        }
    }
    if(ok1||ok2||ok3)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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

    return 0;
}