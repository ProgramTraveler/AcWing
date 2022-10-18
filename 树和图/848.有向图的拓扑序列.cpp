#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;

int h[N], e[N], ne[N], idx; 
int q[N], d[N]; // q 存的是队列 d 存的是入度

void add (int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool topsort () {
    int hh = 0, tt = -1;

    for (int i = 1; i <= n; i ++) { // 插入所有入度为 0 的点
        if (!d[i]) {
            q[++ tt] = i;
        }
    }

    while (hh <= tt) {
        int t = q[hh ++];

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i]; // 找到出边

            d[j] --; // 让它的入度 --
            if (d[j] == 0) q[++ tt] = j;
        }
    }

    return tt == n -1; // 判断一下是不是所有点都已经入队了
}

int main () {
    cin >> n >> m;

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i ++) {
        int a, b;

        add(a, b);
    }

    // 拓扑排序
    if (topsort()) { // 判断一下是否存在拓扑排序 有向无环图都是存在拓扑排序的
        for (int i = 0; i < n; i ++) printf("%d", q[i]); // 处理后队列里存的就是拓扑排序的结果
        
        puts("");
    } else puts("-1");

    return 0;
}