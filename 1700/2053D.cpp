#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define int long long

using namespace std;
namespace __gnu_pbds{
          typedef tree<int,
                       null_type,
                       less_equal<int>,
                       rb_tree_tag,
                       tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds;

void Insert(ordered_set &s,int x){ //this function inserts one more occurrence of (x) into the set.

     s.insert(x);

}

bool Exist(ordered_set &s,int x){ //this function checks weather the value (x) exists in the set or not.

     if((s.upper_bound(x))==s.end()){
        return 0;
     }
     return ((*s.upper_bound(x))==x);

}

void Erase(ordered_set &s,int x){ //this function erases one occurrence of the value (x).

     if(Exist(s,x)){
        s.erase(s.upper_bound(x));
     }

}


int FirstIdx(ordered_set &s,int x){ //this function returns the first index of the value (x)..(0 indexing).

    if(!Exist(s,x)){
        return -1;
    }
    return (s.order_of_key(x));

}


int Value(ordered_set &s,int idx){ //this function returns the value at the index (idx)..(0 indexing).

   return (*s.find_by_order(idx));

}


int LastIdx(ordered_set &s,int x){ //this function returns the last index of the value (x)..(0 indexing).

    if(!Exist(s,x)){
        return -1;
    }
    if(Value(s,(int)s.size()-1)==x){
        return (int)(s.size())-1;
    }
    return FirstIdx(s,*s.lower_bound(x))-1;

}


int Count(ordered_set &s,int x){ //this function returns the number of occurrences of the value (x).

     if(!Exist(s,x)){
        return 0;
     }
     return LastIdx(s,x)-FirstIdx(s,x)+1;

}


void Clear(ordered_set &s){ //this function clears all the elements from the set.

     s.clear();

}


int Size(ordered_set &s){ //this function returns the size of the set.

     return (int)(s.size());

}

const int mod = 998244353;
int64_t pw(int64_t a, int64_t b) {
	int64_t r = 1;
	while(b > 0) {
		if(b & 1) r = (r * a) % mod;
		b /= 2;
		a = (a * a) % mod; 
	}
	return r;
}


void solve()
{  
   int n,q; cin>>n>>q;
   vector<int> A(n);
   vector<int> B(n);
   ordered_set s1,s2;

   for(auto &ele:A)
   {
        cin>>ele;
        Insert(s1,ele);
   }
   for(auto &ele:B)
   {
        cin>>ele;
        Insert(s2,ele);
   }

   int output = 1;

   for(int i=0;i<n;i++)
   {
        int a = Value(s1,i);
        int b = Value(s2,i);
        output = (output*min(a,b))%mod;
   }

   cout << output << " ";

   while(q--)
   {
        int o, x; cin>>o>>x;
        --x;
        int prevval, currval;
        int prevcand;
        int idx;
        if(o==1)
        {
            prevval = A[x];
            idx = LastIdx(s1,prevval);
            prevcand = min(Value(s1,idx),Value(s2,idx));
            A[x]++;
            currval = A[x];
            Erase(s1,prevval);
            Insert(s1,currval);
        }
        else
        {
            prevval = B[x];
            idx = LastIdx(s2,prevval);
            prevcand = min(Value(s1,idx),Value(s2,idx));
            B[x]++;
            currval = B[x];
            Erase(s2,prevval);
            Insert(s2,currval);
        }

        int cand = min(Value(s1,idx),Value(s2,idx));
        
        output = output*pw(prevcand,mod-2)%mod*cand%mod;
        cout << output << " ";
   }

   cout << "\n";



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