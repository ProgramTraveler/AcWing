#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m; // 分别表示点和边

int h[N], e[N], ne[N], idx;

int d[N], q[N];

void add (int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;  
}

int bfs () {
    int hh = 0, tt = 0; // 队头和队尾

    q[0] = 1;

    memset(d, -1, sizeof d);

    d[1] = 0; // 刚开始只有第一个点被遍历过了

    while (hh <= tt) {
        int t = q[hh ++]; // 每次取一下队头元素

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];

            if (d[j] == -1) { // 如果当前点没有被拓展过的话
                d[j] = d[t] + 1;
                q[++ tt] = j;
            }
        }
    }

    return d[n];
}

int main () {
    cin >> n >> m; // 读入点数和边数

    memset(h, -1, sizeof h); // 初始化所有表头

    for (int i = 0; i < m; i ++) { // 读入所有边
        int a, b;
        cin >> a >> b;

        add(a, b);
    }

    cout << bfs() << endl;

    return 0;
}
