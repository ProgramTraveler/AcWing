#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], w[N]; // w 记录的是权重
int dist[N], cnt[N]; // dist[x] 存储 1 号点到 x 的最短距离 cnt[x] 存储 1 到 x 的最短路中经过的点数
bool st[N]; // 哪个点已经是确定的

int add (int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++; 
}

bool spfa () {
    // 不需要初始化 dist 数组
    // 原理：如果某条最短路径上有 n 个点(除了自己) 那么加上自己之后一共有 n + 1 个点，由抽屉原理一定有两个点相同 所以存在环。
    
    queue<int> q;
    for (int i = 1; i <= n; i ++ ) {
        q.push(i);
        st[i] = true;
    }

    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i]) { // 更新 t 的所有领边
            int j = e[i]

            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;

                if (cnt[j] >= n) return true;

                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}

int main () {
    scanf("%d%d", &n, &m);

    // 对图的初始化
    memset(h, -1, sizeof h); // 邻接表的初始化

    while (m --) {
        int a, b, c;

        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
        
    if (spfa()) puts("Yes");
    else puts("No");

    return 0;
}
