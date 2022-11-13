#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

const double eps = 1e-6;

int n;

double a[N][N]; // 系数矩阵

int guss () {
    int c ,r;

    for (c = 0, r = 0; c < n; c ++) {
        int t = r;

        for (int i = r; i < n; i ++) 
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;
    
        if (fabs(a[t][c]) < eps) continue;

        for (int i = c; i <= n; i ++) swap(a[t][i], a[r][i]);
        for (int i = n; i >= c; i --) a[r][i] /= a[r][c];
        for (int i = r + 1; i < n; i ++) 
            if (fabs(a[i][c]) > eps) 
                for (int j = n; j >= c; j --) 
                    a[i][j] -= a[r][j] * a[i][c];

        r ++;
    }

    if (r < n) {
        for (int i = r; i < n; i ++)
            if (fabs(a[i][n]) > eps) return 2; // 无解

        return 1; // 有无穷多解
    }

    return 0; // 有唯一解
}

int main () {
    cin >> n;

    for (int i = 0; i < n; i ++) {
        for (int j  = 0; j < n + 1; j ++) {
            cin >> a[i][j];
        }
    }

    int guss();

    if (t == 0) {
        for (int i = 0; i < n; i ++) printf("%.2lf\n", a[i][n]); // 保留两位小数
    } else if (t == 1) puts("Infinite group solutions"); // 说明有无穷多组解
    else puts("No solution"); // 否则的话就是无解

    return 0;
}