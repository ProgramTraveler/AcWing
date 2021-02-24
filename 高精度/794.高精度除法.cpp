#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A / B, 商是C，余数是r
vector<int> div(vector<int> &A, int b, int &r) { //r是通过引用传回去的
    vector<int> C;
    r = 0;
    //从最高位开始看
    for (int i = A.size() - 1; i >= 0; i -- ) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back(); //去前导零
    return C;
}

int main() {
    string a;
    vector<int> A;

    int B;
    cin >> a >> B;
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');

    int r;
    auto C = div(A, B, r);

    for (int i = C.size() - 1; i >= 0; i -- ) cout << C[i];

    cout << endl << r << endl;

    return 0;
}