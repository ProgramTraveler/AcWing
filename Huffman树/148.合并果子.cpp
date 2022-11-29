#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main () {
    int n;

    scanf("%d", &n);

    priority_queue<int, vector<int>, greater<int>> heap;

    while (n --) {
        int x;
        scanf("%d", &x);

        heap.push(x);
    }

    int res = 0;

    while (heap.size() > 1) {
        int a = heap.top(); heap.pop();

        int b = heap.top(); heap.pop();

        res += a + b;
        heap.push(a + b);


    }

    printf("%d\n", res);

    return 0;
}