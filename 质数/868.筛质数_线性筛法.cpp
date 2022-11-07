#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int primes[N], cnt;
bool st[N];

void get_primes (int n) {
    for (int i = 2; i <= n; i ++) {
        if (!st[i]) primes[cnt ++] = i; // 如果不是质数的话就添加到列表中

        for (int j = 0; primes[j] <= n / i; j ++) {
            st[primes[j] * i] = true;

            if (i % primes[j] == 0) break;
        }
    }
}

int main () {
    int n;

    cin >> n;

    get_primes(n);

    cout << cnt << endl;

    return 0;
}