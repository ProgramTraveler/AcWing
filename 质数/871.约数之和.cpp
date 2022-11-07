#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long LL;

const int mod = 1e9 + 7;

int main () {
    int n;

    cin >> n;

    unordered_map<int, int> primes;

    while (n --) {
        int x;

        cin >> x;

        for (int i = 2; i <= n / i; i ++) {
            while (x % i == 0) {
                x /= i;
                primes[i] ++;
            }
        }

        if (x > 1) primes[x] ++;
    }

    LL res = 1;

    for (auto prime : primes) { // 直接带入求和公式
        int p = prime.first, a = prime.second;

        LL t = 1;

        while (a --) t = (t * p + 1) % mod;

        res = res * t % mod;
    }

    cout << res << endl;

    return 0;
}