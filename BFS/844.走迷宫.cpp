#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

// bfs 解决最短路问题前提是路径权重都是一样的

using namespace std;

typedef pair<int, int> PII;


int n, m;

int g[N][N]; // 存的是迷宫地图 

int d[N][N]; // 每一个点到起点的距离

PII q[N * N];

int bfs () {
    int hh = 0, tt = 0; // 队头和队尾
    q[0] = {0, 0};

    memset(d, -1, sizeof d);

    d[0][0] = 0;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; // 表示四个方向
    while (hh <= tt) { // 队列不空
        auto t = q[hh] ++;

        for (int i = 0; i < 4; i ++) {
            int x = t.first + dx[i], y = t.second + dy[i];

            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) { // 当前点可以走
                d[x][y] = d[t.first][t.second] + 1;
                q[ ++ t] = {x, y};
            }
        }
    }

    return d[n - 1][m - 1];
}

int main () {
    cin >> n >> m;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> g[i][j];
        }
    }

    cout << bfs() << endl;
}