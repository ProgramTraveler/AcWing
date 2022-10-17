#include <iostream>

using namespace std;

const int N = 20;

int n;

int path[N];

char g[N][N];

bool col[n], dg[N], udg[N]; // 行 正对角线 反对角线

void dfs (int u) {
    if (u == n) { // 说明已经找到一组方案
        for (int i = 0; i < n; i ++) puts(g[i]);
        puts("");
        return ;
    }

    for (int i = 0; i < n; i ++) {
        if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true; // 表示放置在该位置
            
            dfs(i + 1);

            // 恢复现场
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
    }

}

int main () {
    cin >> n;

    dfs(0);

    return 0;
}