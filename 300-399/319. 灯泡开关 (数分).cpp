#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/generalized-abbreviation/
/*从我们观察可以发现，如果一个灯泡有奇数个约数，那么最后这个灯泡一定会亮着。

所以其实我们是求，从1-n有多少个数的约数有奇数个。而**有奇数个约数的数一定是完全平方数。
**这是因为，对于数n，如果m是它的约数，则n/m也是它的约数，若m≠n/m，
则它的约数是以m、n/m的形式成对出现的。而m＝n/m成立且n/m是正整数时，n是完全平方数,而它有奇数个约数。

我们再次转化问题，求1-n有多少个数是完全平方数。*/
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};