#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int a[N];

int main () {
    scanf("%d", &n);

    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);

    sort(a, a + n); 

    int res = 0;

    for (int i = 0; i < n; i ++) res += abs(a[i] - a[n / 2]);

    printf("%d\n", res);

    return 0;
}