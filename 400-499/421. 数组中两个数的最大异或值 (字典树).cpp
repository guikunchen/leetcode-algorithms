// https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/
/*首先计算数组中最大数的二进制长度 L。

初始化 max_xor = 0。

从 i = L - 1 遍历到 i = 0（代表着从最左侧的比特位 L - 1 遍历到最右侧的比特位 0）：

	将 max_xor 左移，释放出下一比特位的位置。

	初始化 curr_xor = max_xor | 1（即将 max_xor 最右侧的比特置为 1）。

	遍历 nums，计算出长度为 L - i 的所有可能的按位前缀。

		将长度为 L - i的按位前缀加入哈希集合 prefixes，按位前缀的计算公式如下：num >> i。
	
	遍历所有可能的按位前缀，检查是否存在 p1，p2 使得 p1^p2 == curr_xor。
	比较简单的做法是检查每个 p，看 curr_xor^p 是否存在。
	如果存在，就将 max_xor 改为 curr_xor（即将 max_xor 最右侧的比特位改为 1）。
	如果不存在，max_xor 最右侧的比特位继续保持为 0。

返回 max_xor。
*/

// 也可以通过构建字典树
// 然后遍历每个数字，选择路径尽可能不同的一个点
// 比如寻找001100 最理想的就是110011，如果走的时候没有的话就算了，有的话就挑