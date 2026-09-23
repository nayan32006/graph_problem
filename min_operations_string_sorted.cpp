#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    int makeStringSorted(string s) {
        int n = s.length();

        vector<long long> fact(n + 1, 1);
        vector<long long> invFact(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[n] = modInverse(fact[n]);
        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }

        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        long long totalOps = 0;

        for (int i = 0; i < n; i++) {
            int currentChar = s[i] - 'a';

            long long countSmall = 0;
            for (int c = 0; c < currentChar; c++) {
                countSmall += freq[c];
            }

            if (countSmall > 0) {
                long long currentPerm = fact[n - 1 - i];

                for (int c = 0; c < 26; c++) {
                    if (freq[c] > 0) {
                        currentPerm = (currentPerm * invFact[freq[c]]) % MOD;
                    }
                }

                long long ways = (countSmall * currentPerm) % MOD;
                totalOps = (totalOps + ways) % MOD;
            }

            freq[currentChar]--;
        }

        return totalOps;
    }
};

int main() {
    Solution sol;

    string s1 = "cba";
    string s2 = "aabaa";


    cout << "Test 1 (\"" << s1 << "\"): " << sol.makeStringSorted(s1) << " (Expected: 5)" << endl;
    cout << "Test 2 (\"" << s2 << "\"): " << sol.makeStringSorted(s2) << " (Expected: 2)" << endl;

    return 0;
}