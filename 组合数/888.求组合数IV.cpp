#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 5010;

int primes[N], cnt;

int sum[N]; // 存储每个质数的次数

bool st[N];

void get_primes (int n) { // 线性筛法求素数
    for (int i = 2; i <= n; i ++) {
        if (!st[i]) primes[cnt ++] = i;

        for (int j = 0; primes[j] <= n / i; j ++ ) {
            st[primes[j] * i]  = true;

            if (i % primes[j] == 0) break; 
        }
    }
}

int get (int n, int p) { // 求n！中的次数
    int res = 0;

    while (n) {
        res += n / p;
        n /= p;
    }

    return res;
}

vector<int> mul (vector<int> a, int b) { // 高精度乘低精度模板
    vector<int> c;

    int t = 0;
    
    for (int i = 0; i < a.size(); i ++) {
        t += a[i] * b;
        c.push_back(t % 10);
        t / = 10;
    }

    while (t) {
        c.push_back(t % 10);

        t /= 10;
    }

    return c;
}

int main () {
    int a, b;

    cin >> a >> b;

    get_primes(a);

    for (int i = 0; i < cnt; i ++) {
        int p = primes[i];

        sum[i] = get(a, p) - get(b, p) - get(a - b, p);
    }

    vector<int> res;

    res.push_back(1);

    for (int i = 0; i < cnt; i ++) {
        for (int j = 0; j < sum[i]; j ++) {
            res = mul(res, primes[i]);
        }
    }

    for (int i = res.size() - 1; i >= 0; i --) printf("%d", res[i]);

    puts("");

    return 0;
}