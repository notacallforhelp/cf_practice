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
*/

/*void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}*/

void solve()
{
    int n; cin>>n;
    vector<int> A(n); for(auto &i:A)cin>>i;

    if(n==1)
    {
        cout << "NO\n";
        return;
    }

    int even_sum = 0;
    int odd_sum = 0;
    int left_even = 0;
    int right_even = 0;
    int left_odd = 1;
    int right_odd = 1;

    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            right_even = i;
            even_sum += A[i];
        }
        else
        {
            right_odd = i;
            odd_sum += A[i];
        }
    }

    if(odd_sum==even_sum)
    {
        cout << "YES\n";
        return;
    }
    while(left_even<=right_even&&left_odd<=right_odd)
    {
        int diff = abs(odd_sum-even_sum);

        //cout << left_odd << " " << right_odd << endl;
        //cout << left_even << " " << right_even << endl << endl;

        //cout << odd_sum << " " << even_sum << endl;

        if(odd_sum>even_sum)
        {
            if(left_odd<left_even)
            {
                if(odd_sum-A[left_odd]==even_sum)
                {
                    cout << "YES\n";
                    return;
                }
            }
            if(right_odd>right_even)
            {
                if(odd_sum-A[right_odd]==even_sum)
                {
                    cout << "YES\n";
                    return;
                }
            }
            if(A[left_odd]<=A[right_odd]&&left_odd<left_even)
            {
                odd_sum -= A[left_odd];
                left_odd += 2;
            }
            else if(A[left_odd]>=A[right_odd]&&right_odd>right_even)
            {
                odd_sum -= A[right_odd];
                right_odd -=2;
            }
            else if(A[left_even]<=A[right_even])
            {
                even_sum -= A[left_even];
                left_even += 2;
            }
            else if(A[right_even]<=A[left_even])
            {
                even_sum -= A[right_even];
                right_even -= 2;
            }
        }
        else if(odd_sum<even_sum)
        {
            if(left_even<left_odd)
            {
                if(even_sum-A[left_even]==odd_sum)
                {
                    cout << "YES\n";
                    return;
                }
            }
            if(right_even>right_odd)
            {
                if(even_sum-A[right_even]==odd_sum)
                {
                    cout << "YES\n";
                    return;
                }
            }
            if(A[left_even]<=A[right_even]&&left_even<left_odd)
            {
                even_sum -= A[left_even];
                left_even += 2;
            }
            else if(A[left_even]>=A[right_even]&&right_even>right_odd)
            {
                even_sum -= A[right_even];
                right_even -=2;
            }
            else if(A[left_odd]<=A[right_odd])
            {
                odd_sum -= A[left_odd];
                left_odd +=2 ;
            }
            else if(A[right_odd]<=A[right_even])
            {
                odd_sum -= A[right_odd];
                right_odd -=2 ;
            }
        }

        if(odd_sum==even_sum)
        {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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