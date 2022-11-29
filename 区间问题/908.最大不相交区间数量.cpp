#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;

struct Range {
    int l, r;

    bool operator < (const Range &w) const {
        return r < w.r;
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

    int res = 0, ed = -2e9;

    for (int i = 0; i < n; i ++) {
        if (ed < range[i].l) {
            res ++;

            ed = range[i].r;
        }
    }

    printf("%d\n", res);

    return 0;
}