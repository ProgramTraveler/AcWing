#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], w[N]; // w 记录的是权重
int dist[N]; // dist 表示当前的最短路是多少
bool st[N]; // 哪个点已经是确定的

int add (int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++; 
}

int spfa () {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    queue.push(1);
    st[1] = true; // 当前这个点是不是在队列当中

    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i]) { // 更新 t 的所有领边
            int j = e[i]

            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];

                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
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
        
    int t = spfa();

    if (t == -1) puts("impossible");
    else printf("%d\n", t);

    return 0;
}
