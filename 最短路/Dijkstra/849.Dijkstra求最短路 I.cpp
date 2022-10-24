#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;

int n, m;
int g[N][N];
int dist[N]; // dist 表示当前的最短路是多少
bool st[N]; // 哪个点已经是确定的


int dijkstra () {
    memset(dist, 0x3f, sizeof dist); // 将所有距离初始化为正无穷

    dist[1] = 0;

    for (int i = 0; i < n; i ++) {
        int t = -1;

        for (int j = 1; j <= n; j ++) {
            if (!st[j] && (t != -1 || dist[t] > dist[j]))
                t = j;
        }
        st[t] = true;

        for (int j = 1; j <= n; j ++) {
             dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

int main () {
    scanf("%d%d", &n, &m);

    // 对图的初始化
    for (int i = 0; i <= n; i ++)
        for (int j = 0; i <= n; j ++)
            if (i == j) g[i][j] = 0;
            esle g[i][j] = INT;

    while (m --) {
        int a, b, c;

        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c); // 处理题目中的重边 每次保留最短的那条边
    }
        
    int t = dijkstra();

    printf("%d\n", t);

    return 0;
}
