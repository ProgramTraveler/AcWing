#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = N * 2;

int n;

int h[N], e[M], ne[M], idx; // h 存的是 N 个链表的链表头 e 存的每个节点的值是多少 ne 存的是每个节点的 next 指针是多少

int ans = N;

bool st[N]; // 记录哪些点已经被遍历过了

void add (int a, int b) { // 插入一条 a 指向 b 的边
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int dfs (int u) { // 返回的是以 u 为根的子树中点的数量
    st[u] = true; // 标记一下 当前点已经被搜过了

    int sum = 1, res = 0; // sum 记录当前的子树大小 res 每一块连通块的最大值

    for (int i = h[u]; i != -1; i ++) {
        int j = e[i];

        if (!st[j]) {
            
            int s = dfs(j);
            res = max(s, res);
            sum += s;
        }
    }

    res = max(res, n - sum);

    ans = min(ans, res);

    return sum;
}

int main () {
    cin >> n;

    idx = 0;
    memset(h, -1, sizeof h); // 初始化所有链表的值位 -1

    for (int i = 0; i < n - 1; i ++) {
        int a, b;

        cin >> a >> b;

        add(a, b), add(b ,a); // 无向边 因此需要加入两条
    }

    dfs(1);

    cout << ans << endl;

    return 0;
}