#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int prime () {
    memset(dist, 0x3f, sizeof dist);

    int res = 0; // 最小生成树的所有边的长度之和
    for (int i = 0; i < n; i ++) {
        int t = -1;

        for (int j = 1; j <= n; j ++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }

        if (i && dist[t] == INF) return INF;
        if (i) res += dist[t]; // 只要不是第一个点

        for (int j = 1; j <= n; j ++) { // 更新一下其他点到这个集合的距离
            dist[j] = min(dist[j], g[t][j]);
        }

        st[t] = true;
    }

    return res;
}

int main () {
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g);

    while (m --) { // 输入所有边
        int a, b, c;

        scanf("%d%d%d", &a, &b, &c);

        g[a][b] = g[b][a] = min(g[a][b], c);         
    }

    int t = prime();
    
    if (t == INF) puts("No");
    else printf("%d\n", t);

    return 0;
}