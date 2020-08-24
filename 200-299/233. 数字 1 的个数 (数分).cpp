#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/number-of-digit-one/

// 1601 个位上1的个数
// (1601 / 10 * 1) + min(max(1601 % 10 - 1 + 1, 0), 1);
// (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
// 针对个位，每隔10个数，都有1个1，然后考虑末尾有没有1。
// 针对十位，每个100个数，都有10个1，xx10-xx19。
// 然后考虑这个数最后两位，如果大于19那就直接再加10，如果小于10就加0，处在中间的话就算出个数，
// 两部分加起来就是十位上1的个数。
class Solution {
public:
	int countDigitOne(int n)
	{
	    int countr = 0;
	    for (long long i = 1; i <= n; i *= 10) {
	        long long divider = i * 10;
	        countr += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
	    }
	    return countr;
	}
};