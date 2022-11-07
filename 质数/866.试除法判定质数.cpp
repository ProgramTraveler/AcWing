#include <iostream>
#include <algorithm>

using namespace std;

bool is_prime (int n) { // 判断是否为质数
    if (n < 2) return false;

    /*for (int i = 2; i < n; i ++) 
        if (n % i == 0) return false;*/

    // 对上面的算法进行优化
    for (int i = 2; i <= n / i; i ++)
        if (n % i == 0) return false

    return true; 
}

int main () {

}