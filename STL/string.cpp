#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

/*
size()

empty()

clear()
*/

int main () {
    string a = "wjm";

    // 在字符串后面添加字符
    a += "def";
    a += "c";

    cout << a << endl;

    cout << a.substr(1, 2) << endl; // 第一个参数是字串的起始位置 第二个参数是字串的长度 当长度超过字符串长度时 输出到末尾为止
    cout << a.substr(1) << endl; // 把第二个参数省略掉 就会返回从 1 开始的整个字符串

    printf("%s\n", a.c_str()) // 这样也可以输出整个字符串

    return 0;

}