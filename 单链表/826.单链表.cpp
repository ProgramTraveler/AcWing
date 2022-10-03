#include <iostream>

using namespace std;

const int N = 1000010;

// head 表示头节点 e[i] 表示节点 i 的值 ne[i] 表示节点 i 的 next 指针是多少
// idx 存储当前已经用到哪个节点

int head, e[N], ne[N], idx;

// 初始化
init () {
    head = -1;
    idx = 0;
}

// 将x插到头节点
void add_to_head (int x) {
    e[idx] = x, ne[idx] = head, head = idx, idx ++;
}

// 将 x 插到下标是 k 的点后面
void add (int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    indx ++;
}

// 将下标是 k 的点后面的点删掉
remove (int k) {
    ne[k] = ne[ne[k]]; // 删除的时候并没有关联到 idx
}

int main () {
    int m;
    cin >> m;

    init();

    while (m --) {
        int k, x;
        char op;

        cin >> op;

        if (op == 'H') {
            cin >> x;
            add_to_head(x);
        } else if (op == 'D') {
            cin >> k;
            if (!k) head = ne[head]; // 对头节点的一个特判
            remove(k - 1);
        } else {
            cin >> k >> x;
            add(k - 1, x);
        }
    }

    for (int i = head; i != -1; i = ne[i]) cout << e[i] << " ";

    cout << endl;

    return 0;
}