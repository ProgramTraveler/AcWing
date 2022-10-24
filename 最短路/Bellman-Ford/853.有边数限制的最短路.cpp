#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N = 510, M = 10010;

int n, m;
int dist[N], bakcup[N]; // dist 表示距离

struct Edge {
    int a, b , w;
} edge[M];

int bellman_ford () {
    // 初始化
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < k; i ++) { // 不超过 k 条边 所以迭代 k 次
        memcpy(bakcup, dist, sizeof dist); // 做一个备份

        for (int j = 0; j < m; j ++) {
            int a = edge[j].a, b = edge[j].b, w = edge[j].w;
            dist[b] = min(dist[b], bakcup[a] + w);
        } 
    }

    if (dist[n] > 0x3f3f3f3f / 2) return -1; // 如果 dist[N] 大于一个比较大的数 返回 -1

    return dist[n];
}

int main () {
    scanf("%d%d%d", &n ,&m, &k);

    for (int i = 0; i < m; i ++) { // 读入每条边
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edge[i] = {a, b, w};
    }

    int t = bellman_ford();

    if (t == -1) { // 说明最短路不存在
        puts("impossible");
    } else printf("%d\n", t);

    return 0;
}