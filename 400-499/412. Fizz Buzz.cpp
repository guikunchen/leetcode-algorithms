// https://leetcode-cn.com/problems/fizz-buzz/

// 变多了之后可以考虑用映射
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for(int i = 2; i < n; i += 3) {
            res[i] = "Fizz";
        }
        for(int i = 4; i < n; i += 5) {
            res[i] += "Buzz";
        }
        for(int i = 1;i <= n; i++)
        {
            if(res[i-1].empty())
            res[i-1] = to_string(i);
        }
        return res;
    }
};