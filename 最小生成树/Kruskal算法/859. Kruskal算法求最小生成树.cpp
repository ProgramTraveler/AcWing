#include <iostream>
#include <algorith>

using namespace std;

const int N = 200010;

int n, m;
int p[N];

struct Edge {
    int a, b, w;

    bool operator < (const Edge &W) const { // 运算符重载 方便排序 按权重来排序
        return w < W.w
    }
} edges[N];

int find (int x) {
    if (p[x] != x) p[x] = find(p[x]);

    return p[x];
} 

int main () {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i ++) {
        int a, b, w;

        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }

    sort(edges, edges + m); // 把所有边排序

    for (int i = 0; i <= n; i ++) { // 初始化所有的并查集
        p[i] = i;
    }

    int res = 0, cnt = 0;
    for (int i = 0; i < m;  i ++) { // 从小到大枚举所有边
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b); // 祖宗节点

        if (a != b) { // 判断一下两个点是不是连通的
            p[a] = b; // 两个集合合并

            // 如果不是连通的 就把这条边加进来
            res += w; // res 存的是最小生成树的所有权重之和

            cnt ++; // 存的是边数之和
        }
    }

    if (cnt < n -1) { // 说明图是不连通的
        puts("impossible");
    } else printf("%d\n", res);

    return 0;
}

/*
int kruskal()
{
    sort(edges, edges + m);

    for (int i = 1; i <= n; i ++ ) p[i] = i;    // 初始化并查集

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i ++ )
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);
        if (a != b)     // 如果两个连通块不连通，则将这两个连通块合并
        {
            p[a] = b;
            res += w;
            cnt ++ ;
        }
    }

    if (cnt < n - 1) return INF;
    return res;
}
*/