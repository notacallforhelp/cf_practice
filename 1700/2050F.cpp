#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
typedef long long ll;
typedef long double ld;

const int MAXN = 2e5+10;
const int K = 25;

int st[K+1][MAXN];
int lg[MAXN];

void solve()
{  
    int n,q; cin>>n>>q;
    vector<int> A(n); for(auto &ele:A) cin>>ele;
    vector<int> vec(n-1);

    for(int i=1;i<n;i++)
    {
        vec[i-1]=max(A[i],A[i-1])-min(A[i],A[i-1]);
    }

    for(int i=0;i<n-1;i++)
    {
        st[0][i]=vec[i];
    }

    for(int i=1;i<=K;i++)
    {
        for(int j=0;j+(1ll<<i)<=n-1;j++)
        {
            st[i][j] = __gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }

    while(q--)
    {
        int a,b; cin>>a>>b;

        if(a==b)
        {
            cout << 0 << " ";
            continue;
        }

        --a;
        b -=2;

        int len = b-a+1;
        int p = lg[len];

        int ans = __gcd(st[p][a],st[p][b-(1ll<<p)+1]);

        cout << ans << " ";
    }

    cout << "\n";


}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.precision(20);

    lg[1]=0;
    for(int i=2;i<MAXN;i++)
    {
        lg[i]=lg[i/2]+1;
    }

    int t; cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}