#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    int V = 0, Y = 0, n = 0, g = 0, c = 0;
    for (char ch : S) {
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            V++;
        else if (ch == 'Y')
            Y++;
        else if (ch == 'N')
            n++;
        else if (ch == 'G')
            g++;
        else
            c++;
    }
    int C_reg = c + n + g;          // total regular consonant letters
    int total = S.length();
    int max_k = total / 3;           // each syllable needs at least 3 letters
    int ans = 0;

    for (int k = 0; k <= max_k; ++k) {
        int a_min = max(0, k - V);   // minimal Y needed as vowels
        if (a_min > Y) continue;     // not enough Y to cover vowel shortage

        int bound = C_reg + Y - a_min - 2 * k; // from inequality: C_reg + Y - a_min - p >= 2k
        if (bound < 0) continue;

        int p = min({n, g, bound, 2 * k}); // p ≤ 2k because total consonant sounds = 2k
        ans = max(ans, 3 * k + p);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}