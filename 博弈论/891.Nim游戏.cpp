/*
    先手必胜状态 -> 可以走到某一个必败状态
    先手必败状态 -> 走不到任何一个必败状态
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    int n;

    int res = 0;

    scanf("%d", &n);

    while (n --) {
        int x;

        scanf("%d", &x);

        res ^= x;
    }

    if (res) puts("Yes");
    else puts("No");

    return 0;
}