#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010;

int n, m;
int h[N], e[M], ne[M], idx; // 邻接表存储图
int color[N]; // 表示每个点的颜色 -1表示未染色 0表示白色 1表示黑色

void add (int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool dfs (int u, int c) { // u表示当前节点 c表示当前点的颜色
    color[u] = c;

    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!color[j]) { // 如果当前这个点没有被染颜色
            if (!dfs(j, 3 - c)) { // 3 - c 可以把 1 变成 2 把 2 变成 1
                return false;
            } else if (color[j] == c) { // 如果已经染过颜色了 而且和当前颜色有矛盾
                return false;
            }
        }
    }

    return true;
}

int main () {
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    while (m --) {
        int a, b;

        scanf("%d%d", &a, &b);

        add(a, b), add(b, a);
    }

    // 开始染色
    bool flag = true; // 染的时候是否有矛盾发生
    for (int i = 0; i <= n; i ++ ) {
        if (!color[i]) { // 如果当前这个点没有被染色的话
            if (!dfs(i, 1)) { // 如果有矛盾发生 
                flag = false;
                break;
            }
        }
    }

    if (flag) puts("Yes");
    else puts("No");

    return 0;
}

/*
bool check () {
    memset(color, -1, sizeof color);
    bool flag = true;
    for (int i = 1; i <= n; i ++)
        if (color[i] == -1)
            if (!dfs(i, 0)) {
                flag = false;
                break;
            }
    return flag;
}
*/