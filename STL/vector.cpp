#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
size()  // 返回元素个数

empty()  // 返回是否为空

clear()  // 清空

front() / back() // 返回第一个数 / 返回最后一个数

push_back() / pop_back() // 在最后插入一个数 / 把最后一个数删掉

begin() / end() // vector 的第 0 个数 / vector 的最后一个数的后面一个数
*/

int main () {
    vector<int> a;

    for (int i = 0; i < 10; i ++) a.push_back(i);

    for (int i = 0; i < a.size(); i ++) cout << a[i] << ' ';
    cout << endl;

    // vector 的迭代器来遍历
    for (vector<int> :: iterator i = a.begin(); i != a.end(); i ++) cout << *i << ' '; // a.begin() 其实就是 a[0] a.end() 就是 a.size()
    cout << endl;

    for (auto i = a.begin(); i != a.end(); i ++) // 也可以把上一个这样写

    for (auto x : a) cout << x << ' ';
    cout << endl;

    // 支持比较运算

    vector<int> a(4, 3) b(3, 4);

    if (a < b) { // 可以比较 vector 之间的大小 按字典序来比

    }

    return 0;
}