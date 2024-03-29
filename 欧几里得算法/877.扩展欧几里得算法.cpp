#include <iostream>

using namespace std;

// 欧几里得算法
int exgcd (int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;

        return a;
    }

    int d = exgcd(b, a % b, y, x);

    y -= a / b * x;

    return d;
}

int main () {
    int n;

    scanf("%d", &n);

    while (n --) {
        int a, b, x, y;

        scanf("%d%d", &a, &b);

        exgcd(a, b, x, y);

        printf("%d %d\n", x, y);
    }

    return 0;
}