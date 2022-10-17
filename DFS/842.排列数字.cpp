#include <iostream>

using namespace std;

const int N = 10;

int n;

int path[N];

bool st[N]; // 表示哪些数字已经被用过了

void dfs (int u) {
    if (u == n) { // 说明已经把所有位置填满了
        for (int i = 0; i < n; i ++) printf("%d", path[i]);
        puts("");
        return ;
    }

    for (int i = 1; i <= n; i ++) {
        if (!st[i]) {
            path[u] = i;
            st[i] = true; // i 已经被用过了
            
            dfs(i + 1);

            // 恢复现场
            st[i] = false; 
        }
    }

}

int main () {
    cin >> n;

    dfs(0);

    return 0;
}