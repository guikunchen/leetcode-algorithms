// https://leetcode-cn.com/problems/sentence-screen-fitting
/*给你一个 rows x cols 的屏幕和一个用 非空 的单词列表组成的句子，请你计算出给定句子可以在屏幕上完整显示的次数。

注意：
一个单词不能拆分成两行。
单词在句子中的顺序必须保持不变。
在一行中 的两个连续单词必须用一个空格符分隔。
句子中的单词总量不会超过 100。
每个单词的长度大于 0 且不会超过 10。
1 ≤ rows, cols ≤ 20,000.

示例 1：
输入：
rows = 2, cols = 8, 
句子 sentence = ["hello", "world"]
输出：
1
解释：
hello---
world---
字符 '-' 表示屏幕上的一个空白位置。
 
示例 2：
输入：
rows = 3, cols = 6, 
句子 sentence = ["a", "bcd", "e"]
输出：
2
解释：
a-bcd- 
e-a---
bcd-e-
字符 '-' 表示屏幕上的一个空白位置。*/

class Solution {// 先看看1行能不能放下完整的句子
public:// 然后不能放下完整句子的空位，从 i 单词开始放（i=0…n-1），下一行的开头是哪个单词
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
    	int n = sentence.size(), i, j, len = 0, ans = 0;
    	vector<int> wordlen(sentence.size());
    	for(i = 0; i < n; ++i)
    	{
    		len += sentence[i].size()+1;
    		wordlen[i] = sentence[i].size();
    	}
    	len--;//一个句子的长度
    	if(cols >= len)//能放下完整的句子
    	{
	    	ans += cols/(len+1)*rows;//带一个空格能放下几个句子
	    	cols = cols%(len+1);//只用考虑剩余的不完整空格
	    	if(cols%(len+1) == len)//不带空格正好还有一个位置
	    	{
	    		ans += rows;
	    		return ans;
	    	}
	    }

    	vector<int> dp(n);//每行从i单词开始填，可以填到哪个单词
    	for(i = 0 ;i < n; i++)
    	{
    		j = i;
    		len = 0;
    		while(len+wordlen[j] <= cols)
    		{
    			len += wordlen[j]+1;//+1是空格
    			j = (j+1)%n;
    		}
    		dp[i] = j;//i单词开始放，放完该行可以到j单词（不含j）
    	}
    	for(i = 0, j = 0; i < rows; i++)
    	{
    		if(dp[j] < j)//放满了一行，dp[j]跑到 j 前面去了
    			ans++;
    		j = dp[j];//下一行从dp[j]单词开始放
    	}
    	return ans;
    }
};