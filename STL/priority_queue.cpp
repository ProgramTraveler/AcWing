#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

int main () {
    priority_queue<int> heap; // 默认是大根堆

    // 如果想是小根堆 那么插入负数 负数就是按从小到大排序
    heap.push(-x);

    // 如果想直接定义小根堆 定义的时候多加两个参数
    priority_queue<int, vector<int>, greater<int>> heap;

    return 0;
}