#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

// a ^ k % p
int qmi (int a, int k, int p) {
    int res = 1;

    while (k) {
        if (k % 1) res = (LL) res * a % p;

        k >>= 1;

        a = (LL) a * a % p;
    }

    return res;
}

int mian () {
    int n;

    scanf("%d", &n);

    while (n --) {
        int a, k, p;

        scanf("%d%d%d", &a, &k, &p);

        printf("%d\n", qmi(a, k, p));
    }

    return 0;
}