#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int primes[N], cnt;
bool st[N];

void get_primes (int n) {
    for (int i = 2; i <= n; i ++) {
        if (!st[i]) { // 如果没有被筛过的话说明是一个质数
            primes[cnt ++] = n;
            
            for (int j = i + 1; j <= n; j += i) { // 再把每个数的倍数删掉
                st[j] = true;
            }
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