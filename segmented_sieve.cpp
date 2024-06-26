#include <bits/stdc++.h>
using namespace std;

const int sz = 1e6;
int sieve[sz + 1];

void generate() {
    for (int i = 2; i <= sz; i++) sieve[i] = 1;
    sieve[0] = sieve[1] = 0;
    
    for (int i = 2; i * i <= sz; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= sz; j += i) sieve[j] = 0;
        }
    }
}

vector<int> solve() {
    vector<int> ds;
    for (int i = 2; i <= sz; i++) {
        if (sieve[i]) ds.push_back(i);
    }
    return ds;
}

int main() {
    generate();
    int t;
    cin >> t;
    vector<int> primes = solve(); // Get all primes up to sz
    
    while (t--) {
        int m, n;
        cin >> m >> n;
        
        vector<int> dummy(n - m + 1, 1); // Initialize dummy array with 1
        
        for (auto &itr : primes) {
            if (itr * itr > n) break;
            int fmp = (m / itr) * itr;
            if (fmp < m) fmp += itr;
            for (int j = max(fmp, itr * itr); j <= n; j += itr) {
                dummy[j - m] = 0;
            }
        }
        
        for (int i = 0; i < n - m + 1; i++) {
            if (dummy[i] && (i + m) > 1) cout << i + m << endl;
        }
    }
    return 0;
}
