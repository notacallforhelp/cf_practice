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
    int l, r, index;
    bool operator < (const range &other) const
    {
        if(l == other.l)
            return r > other.r;
        return l < other.l;
    }
};

/*
FOR SIMULATING ALL CELLS THAT SHARE A WALL WITH CURRENT CELL, GRID IS OF SIZE N*M

int dx[] = {-1, 0, +1, 0};
int dy[] = {0, -1, 0, +1};

inline bool in(int i, int j) {
    return (0 <= i && i < n && 0 <= j && j < m);
}

binary exp 

ll binpow(ll a, ll b)
{
    if(b == 0)
    {
        return 1;
    }
    if(b % 2)
    {
        return (a * binpow(a, b - 1)) % mod;
    }
    return binpow((a * a) % mod, b / 2);
}

ceil 

ll ceil2(ll a, ll b) {
    if (a == 0) return 0;
    return (a - 1) / b + 1;
}

COMBINATORICS TEMPLATE 
*/

const int N = 1e5 + 10;
const int mod = 10;
int fact[N];
int cnt2[N];
int cnt5[N];

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
    int output = (fact[n] * pw((fact[n - k] * fact[k]) % mod, 3)) % mod;

    int numerator2 = cnt2[n];
    int numerator5 = cnt5[n];

    int denominator2 = cnt2[k] + cnt2[n - k];
    int denominator5 = cnt5[k] + cnt5[n - k];

    if(numerator2 >= denominator2)
    {
        int tomul = numerator2 - denominator2;
        for(int i = 0; i < tomul; i++)
        {
            output = (output * 2) % 10;
        }
    }

    if(numerator5 >= denominator5)
    {
        int tomul = numerator5 - denominator5;
        for(int i = 0; i < tomul; i++)
        {
            output = (output * 5) % 10;
        }
    }
    
    if(numerator2<denominator2)
    {
        int todiv = denominator2 - numerator2;
        for(int i = 0; i < todiv; i++)
        {
            output = (output / 2) % 10;
        }
    }

    
    if(numerator5<denominator5)
    {
        int todiv = denominator5 - numerator5;
        for(int i = 0; i < todiv; i++)
        {
            output = (output / 5) % 10;
        }
    }

    return output % 10;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.precision(20);

    fact[0] = 1;
    cnt2[0] = 0;
    cnt5[0] = 0;

    for(int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1];
        cnt2[i]=cnt2[i-1];cnt5[i]=cnt5[i-1];
        
        int gen = i;
        while(gen>0&&gen%2==0)
        {
            gen /=2;
            ++cnt2[i];
        }
        while(gen>0&&gen%5==0)
        {
            gen/=5;
            ++cnt5[i];
        }
        fact[i] *= gen;
        fact[i] %=10;
    }

    cout << C(13, 6) << endl;

    return 0;
}