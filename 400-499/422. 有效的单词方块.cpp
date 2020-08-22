// https://leetcode-cn.com/problems/valid-word-square
/*给你一个单词序列，判断其是否形成了一个有效的单词方块。
示例 2：
输入：
[
  "abcd",
  "bnrt",
  "crm",
  "dt"
]
输出：
true
解释：
第 1 行和第 1 列都是 "abcd"。
第 2 行和第 2 列都是 "bnrt"。
第 3 行和第 3 列都是 "crm"。
第 4 行和第 4 列都是 "dt"。
因此，这是一个有效的单词方块。
*/

// 检查单词长度是否等于单词个数，有超过行数的，直接返回false
// 短的，补上空格
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
    	int m = words.size(), i, j;
    	for(i = 0; i < m; ++i)
    	{
    		if(words[i].size() > m)// 超过行数的，直接返回false
    			return false;
    		if(words[i].size() < m)
    			words[i] += string(m-words[i].size(),' ');// 短的，补上空格
    	}
		for(i = 0; i < m; ++i)
		{
			for(j = 0; j < m; ++j)
			{
				if(words[i][j] != words[j][i])
					return false;
			}
		}
		return true;
    }
};