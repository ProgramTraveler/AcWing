#include <iostream>
#include <algorithm>

using namespace std;

void divide (int n) {
    /*for (int i = 2; i <= n; i ++)  // 从小到大枚举 n 的所有质因数
        if (n % i == 0) { // i 一定是质数
            int s = 0;
            while (n % i == 0) {
                n /= i;
                s ++; 
            }

            printf("%d%d\n", i, s);
        }*/

    for (int i =  2; i <= n / i; i ++) {
        if (n % i == 0) { // i 一定是质数
            int s = 0;
            while (n % i == 0) {
                n /= i;
                s ++; 
            }

            printf("%d%d\n", i, s);
        }
    }
    if (n > 1) printf("%d%d\n", n, 1);
    puts("");
}

int main () {
    int n;

    scanf("%d", &n);

    while (n --) {
        int x;
        scanf("%d", &x);
        divide(x);
    }

    return 0;
}