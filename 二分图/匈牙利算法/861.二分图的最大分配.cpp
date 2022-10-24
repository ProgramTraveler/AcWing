#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, M = 1000010;

int n1, n2, m;
int h[N], e[M], ne[M], idx; // 邻接表
int match[N]; // 存储第二个集合中的每个点当前匹配的第一个集合中的点是哪个
bool st[N]; // 表示第二个集合中的每个点是否已经被遍历过

void add (int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool find (int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) { // 如果没有考虑过
            st[j] = true;
            
            if (match[j] == 0 || find(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }

    return false;
}

int main () {
    scanf("%d%d%d", &n1, &n2, &m);

    memset(h, -1, sizeof h);

    while (m --) {
        int a, b;

        scanf("%d%d", &a, &b);
        add(a, b);
    }
    
    int res = 0; // 当前匹配的数量
    for (int i = 1; i <= n1; i ++) {
        memset(st, false, sizeof st);

        if (find(i)) res ++;
        else 
    }

    printf("%d\n", res);

    return 0;
}