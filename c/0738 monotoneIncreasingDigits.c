/*
给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。

（当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）

示例 1:

输入: N = 10
输出: 9
示例 2:

输入: N = 1234
输出: 1234
示例 3:

输入: N = 332
输出: 299
说明: N 是在 [0, 10^9] 范围内的一个整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/monotone-increasing-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int monotoneIncreasingDigits(int N)
{
    int i   = 1;
    int res = N;
    int n;
    while(i <= res / 10)
    {
        n = (res / i) % 100;  // 取当前数据的个位和十位
        i *= 10;

        if(n / 10 > n % 10)         // 如果十位大于个位
            res = res / i * i - 1;  //例如1332 循环第一次变为1330-1=1329 第二次变为1300-1=1299
    }
    return res;
}

int main(void)
{
    printf("%d\n", monotoneIncreasingDigits(332));
    return 0;
}
