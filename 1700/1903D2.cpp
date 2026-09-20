#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<int> A(n);
    long long sum_A = 0;
    // Frequency array of our starting numbers
    vector<int> freq(1 << 20, 0); 
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        freq[A[i]]++;
        sum_A += A[i];
    }

    // dp[mask] = total cost to make ALL elements a superset of mask
    vector<long long> dp(1 << 20, 0);

    // Loop over every possible highest missing bit 'j'
    for (int j = 0; j <= 19; j++) {
        int limit = 19 - j;
        int size = 1 << limit;
        
        vector<long long> C(size, 0); // Count of elements
        vector<long long> S(size, 0); // Sum of their "loose change"
        
        // 1. Isolate elements missing bit j
        for (int x = 0; x < (1 << 20); x++) {
            if (freq[x] > 0 && ((x & (1 << j)) == 0)) {
                int y = x >> (j + 1); // Extract the upper bits
                C[y] += freq[x];
                S[y] += (long long)freq[x] * (x & ((1 << j) - 1)); // Save the loose change
            }
        }
        
        // 2. Sum Over Supersets (SOS DP)
        for (int i = 0; i < limit; i++) {
            for (int mask = size - 1; mask >= 0; mask--) {
                if (!(mask & (1 << i))) {
                    C[mask] += C[mask | (1 << i)];
                    S[mask] += S[mask | (1 << i)];
                }
            }
        }
        
        // 3. Add contributions to the global dp array
        for (int y = 0; y < size; y++) {
            if (C[y] == 0) continue; 
            
            // Reconstruct the higher part of the mask
            int high = (y << (j + 1)) | (1 << j);
            long long c = C[y];
            long long s = S[y];
            
            // Iterate all possible lower bits and apply the cost formula
            for (int low = 0; low < (1 << j); low++) {
                int mask = high | low;
                long long rem_mask = mask & ((1 << (j + 1)) - 1);
                dp[mask] += c * rem_mask - s;
            }
        }
    }

    // The threshold where we can just push all elements safely to 2^20
    long long max_cost_20 = (long long)n * (1LL << 20) - sum_A;

    while (q--) {
        long long k;
        cin >> k;
        
        if (k >= max_cost_20) {
            // Infinite budget bypass!
            cout << (k + sum_A) / n << "\n";
        } else {
            // Standard Greedy query using our precalculated DP
            long long ans = 0;
            for (int bit = 19; bit >= 0; bit--) {
                if (dp[ans | (1 << bit)] <= k) {
                    ans |= (1 << bit);
                }
            }
            cout << ans << "\n";
        }
    }
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}