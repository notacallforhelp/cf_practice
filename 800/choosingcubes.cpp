#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


typedef long long int ll;
typedef long double ld;

//ordered_sets
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

//struct for range 
struct range
{
    ll l,r,index;
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

*/

void solve()
{
    int n, f, k; cin>>n>>f>>k;

    vector<pair<int,int>> A(n);

    vector<int> hsh(105,0);

    for(int i=0;i<n;i++)
    {
        cin>>A[i].first;
        ++hsh[A[i].first];
        A[i].second = i+1;
    }
    int mainpart = A[f-1].first;
    //cout << mainpart << endl;
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());

    //cout << A[k].first <<" "<<mainpart<< endl;
        if(A[k-1].first<mainpart)
        {
            cout << "YES" << endl;
            return;
        }
        else if(A[k-1].first>mainpart)
        {
            cout << "NO" << endl;
            return;
        }
        else
        {
            if(A[k].first==mainpart)
            {
                cout << "MAYBE" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int t; cin>>t;

    while(t--)
    {
        solve();
    }
}