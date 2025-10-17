#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


typedef long long int ll;
typedef long double ld;
#define int long long

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

FOR SIMULATING ALL CELLS THAT SHARE A WALL WITH CURRENT CELL, GRID IS OF SIZE N*M

int dx[]={-1,0,+1,0};
int dy[]={0,-1,0,+1};

inline bool in(int i,int j){
    return (0<=i&&i<n&&0<=j&&j<m);
}

*/

int sumOfDigitsFrom1ToNUtil(int n, vector<int> &a) {
    if (n < 10)
        return (n * (n + 1) / 2);

    int d = 0; 
    int temp = n;
    while(temp > 0) {
        d++;
        temp /= 10;
    }
    
    int p = 1;
    for(int i = 1; i < d; i++) {  // Changed to d-1 iterations
        p *= 10;
    }

    int msd = n / p;
    int remainder = n % p;

    return (msd * a[d-1] + (msd * (msd - 1) / 2) * p 
            + msd * (1 + remainder) + sumOfDigitsFrom1ToNUtil(remainder, a));
}

int sumOfDigits(int n) {
    if (n <= 0) return 0;
    
    int d = 0; 
    int temp = n;
    while(temp > 0) {
        d++;
        temp /= 10;
    }
    
    vector<int> a(d + 1);
    a[0] = 0;
    a[1] = 45;

    int mul = 1;
    for (int i = 2; i <= d; i++) {
        mul *= 10;
        a[i] = a[i - 1] * 10 + 45 * mul;
    }

    return sumOfDigitsFrom1ToNUtil(n, a);
}

void solve()
{
    cout << ("axqucrgfdshcpqjcqaxquczgfdshcpqjcqaxquczgfdshcpqjcqaxquczgfdshcpqjcqaxquczgfdshcpqjcqaxquc"=="axqucrgfdshcpqjcqaxquczgfdshcpqjcqaxquczgfdshcpqjcqaxquczgfdshcpqjcqaxquczgfdshcpqjcqaxquc")<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    /*int sum = 0;
    int sum2 = 0;

    int n; cin>>n;

    for(int i=0;i<=n;i++)
    {
        sum += i%10;
        sum2 += (i/10)%10;
    }

    cout << sum << endl;

    cout << (n/10)*45 + (n%10)*((n%10)+1)/2 << endl;

    cout << sum2 << endl;

    cout << (n/100)*(450) + (max((n%100)-10,0ll)/10)*(max((n%100)-10,0ll)/10 +1)*5 + ((n%10)+1)*((n%100)/10);*/

    cout << sumOfDigits(328)<<endl;;


}