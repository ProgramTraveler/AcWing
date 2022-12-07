#include <iostream>
#include <vector>

using namespace std;


vector<int> mul(vector<int> &A, int b) {
    vector<int> C;

    int t = 0; // 进位
    for (int i = 0; i < A.size() || t; i ++ ) { // 当数字没有处理完或者还有进位没有处理完，就一直循环
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back(); // 用来考虑 b = 0 的情况的，如果 b != 0 是不是就不用加

    return C;
}


int main() {
    string a;
    int b;

    cin >> a >> b;

    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');

    auto C = mul(A, b);

    for (int i = C.size() - 1; i >= 0; i -- ) printf("%d", C[i]);

    return 0;
}