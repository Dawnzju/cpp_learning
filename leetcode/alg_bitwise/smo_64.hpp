//
// Created by Edward on 2020/2/23.
//
#include "../lib.hpp"
/*
面试题64. 求1+2+…+n
    求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

示例 1：
    输入: n = 3
    输出: 6

示例 2：
    输入: n = 9
    输出: 45

限制：
    1 <= n <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/qiu-12n-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
 解题思路:
    + && 的短路特性 (A && B)
        (1) A 为 true，则返回表达式 B 的 bool 值
        (2) A 为 false，则返回 false
 */

int sumNums(int n) {
    n && (n+=sumNums(n-1));
    return n;
}