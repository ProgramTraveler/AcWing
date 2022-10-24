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

int dijkstra () {
    memset(dist, 0x3f, sizeof dist); // 将所有距离初始化为正无穷

    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while (heap.size()) { // 堆不空
        auto t = heap.top();
        heap.pop();

        int ver = t.second(), distance = t.first();
        if (st[ver]) continue;

        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];

            if (dist[j] > distance + w[j]) {
                dist[j] = distance + w[j];
                heap.push({dist[j], j});
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
        
    int t = dijkstra();

    printf("%d\n", t);

    return 0;
}
