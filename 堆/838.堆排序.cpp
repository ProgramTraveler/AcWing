#include <iostream>
#include <algorithm> // 导入额外的库

using namespace std;

const int N = 100010;

int n , m;

int h[N], size; // size 表示当前 h 有多少元素

void down (int u) { // down 操作
    int t = u;
    if (u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;

    if (u != t) { // 如果 u 不等于 t 说明根节点不是最小值
        swap(h[u], h[t]); // 交换一下最小值 继续执行 down 操作
        down(t);
    }
}

void up (int u) { // up 操作
    while (u / 2 && h[u / 2] > h[u]) {
        swap(h[u / 2], h[u]);
        u /= 2;
    }
}

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &h[i]);
    size = n;

    // 构建堆
    for (int i = n / 2; i; i --) down(i);

    while (m --) {
        printf("%d", h[1]); // 输出堆顶元素
        // 维护堆
        h[1] = h[size];
        size --;
        down(1);
    }

    return 0;
}