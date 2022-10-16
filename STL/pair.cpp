#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

/*
first // 第一个元素

second // 第二个元素

支持比较运算 也是按字典序 以 first 为第一关键字 以 second 为第二关键字 

*/

int main () {
    pair<int, string> p;

    // 初始化 pair 的两种方式
    // 第一种方式
    p = make_pair(10, "wjm");
    //第二种方式
    p = {20, "wjm"};

    // 也可以用 pair 存储三个属性
    pair<int, pair<int, int>> p;

    return 0;
}