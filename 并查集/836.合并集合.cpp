#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N]; // 每个元素的父节点是谁

int find (int x) { // 返回 x 所在集合的编号 x 的祖宗节点 + 路劲压缩
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main  () {
    scanf("%d%d", &n ,&m);

    for (int i = 1; i <= n; i ++) p[i] = i; // 初始的时候每个集合里只有一个元素 因此每个元素都是自己的父节点

    while (m --) {
        char op[2];
        int a, b;

        scanf("%s%d%d". op, &a, &b);

        if (op[0] == 'M') p[find(a)] == find(b); // 合并集合
        else {
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }

    } 
    return 0;
}
