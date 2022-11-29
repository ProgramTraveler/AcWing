#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n;
struct Range {
    int l, r;
    bool operator < (const Range &w) const {
        return l < w.l;
    }
}range[N];

int main () {
    scanf("%d", &n);

    for (int i = 0; i < n; i ++) {
        int l, r;

        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }

    sort(range, range + n);

    priority_queue<int, vector<int>, greater<int>> heap;

    for (int i = 0; i < n; i ++) {
        auto r = range[i];

        if (heap.empty || heap.top() >= r.l) heap.push(r.r);
        else {
            int t = heap.top();

            heap.pop();
            heap.push(r.r);
        } 
    }

    printf("%d\n", heap.size());

    return 0;

}