#include <iostream>
#include <algorithm>

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
    int st, ed;
    scanf("%d%d", &st, &ed);

    scanf("%d", &n);

    for (int i = 0; i < n; i ++) {
        int l, r;

        scanf("%d%d", &l, &r);

        rang[i] = {l, r};
    }

    sort(range, range + n);

    int res =  0;
    bool success = false;

    for (int i = 0; i < n; i ++) {
        int j  = i, r = -2e9;
        while (j < n && range[j].l <= st) {
            r = max(r, range[j].r);
            j ++;
        }
        if (r < st) {
            res = -1;
            break;
        }

        res ++;

        if (r >= ed) {
            success = true;

            break;
        }
        
        st = r;
        i = j - 1;
    }

    if (!success) res = -1;

    printf("%d\n", res);

    return 0;
}