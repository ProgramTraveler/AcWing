#include <iostream>

using namespace std;

const int N = 100010;

int son[N][26], cnt[N], idx; // son 是子节点 cnt 以当前这个字母结尾的单词有多个 idx 当前用到的下标 下标是 0 的点既是根节点 又是空节点 
char str[N];

// 插入操作
void insert (char str[]) {
    int p = 0; // 从根节点开始

    for (int i = 0; str[i]; i ++) {
        int u = str[i] - 'a';

        if (!son[p][u]) { // 如果当前节点的子节点没有这个字母
            son[p][u] = ++ idx;
        }

        p = son[p][u];
    }

    cnt[p] ++;
}

// 查询操作 
int query (char str[]) { // 返回的是这个字符串出现多少次
    int p = 0;

    for (int i = 0; str[i]; i ++) {
        int u = str[i] - 'a';

        if (!son[p][u]) return 0;

        p = son[p][u];
    }

    return cnt[p];
}

int main () {
    int n;
    
    scanf("%d", &n);
    while (n --) {
        char op[2];
        scanf("%s%s", op, str);

        if (op[0] == 'I') insert(str);
        else print("%d\n", query(str));
    }

    return 0;
}