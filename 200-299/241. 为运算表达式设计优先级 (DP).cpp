#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/different-ways-to-add-parentheses/


/*动态规划
    首先将字符串中的数字和操作符分别存储下来
    第i个操作符对应的数字是i和i+1，同理第i个数的前面的操作符是i-1，后面的一个是i（i表示在数组中的序号）
    dp[i][j]表示从第i个数字到第j个数字的所有情况
        （1）i==j
            等于数字本身的值
        （2）i != j(j肯定是大于i的) 
            将i-j分成两个式子来看，[i,i]op[i+1,j],[i,i+1]op[i+2,j]...[[i,j-1]]op[j,j]
            将上面的所有情况全部组合起来
现在需要考虑一个问题是[i,i+k]op[i+k+1,j]的op应该是ops数组里面的哪一个，应该是ops[i+k]
有了以上，我们就可以写出动态规划了，还有一个需要注意的地方是，
（2）情况也就是一个遍历，但是遍历的顺序需要注意，不应该是[0,j]->[j-1,j]而应该是[j-1,j]->[0->j]。
如果是从[0,j]开始，你会发现[1,j]..[j-1,j]这些你需要的都还没算
*/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> ops;
        int num = 0;
        for(int i = 0; i < input.size(); i++){
            if(isOp(input[i])){
                nums.push_back(num);
                ops.push_back(input[i]);
                num = 0;
            }
            else
                num = num * 10 + input[i] - '0';
        }
        nums.push_back(num);// 以上步骤存储所有的数字和操作符
        int n = nums.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n));
        for(int i = 0; i < n; i++)
            dp[i][i].push_back(nums[i]);// dp[i][i]就是数字本身
        for(int j = 1; j < n; j++){
            for(int i = j-1; i >= 0; i--){
                for(int k = i; k < j; k++){
                    for(int r1 : dp[i][k]){
                        for(int r2 : dp[k+1][j]){
                            dp[i][j].push_back(calculate(r1,ops[k],r2));
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }

    bool isOp(const char& c){
        return c == '+' || c == '-' || c == '*';
    }

    int calculate(const int& num1, const char& op, const int& num2){
        if(op == '+')
            return num1 + num2;
        else if(op == '-')
            return num1 - num2;
        else
            return num1 * num2;
    }
};

/*
分治归并
    以操作符为界限，将运算表达式分割为两个不同的部分，在递归计算（在这个运算符处分割，其实也是代表将这个运算符最后一个算）
    递归终止条件：字符串中就一个数字

    在递归的过程中，会有一部分字符串会重复多次计算，所以在前面的基础上加入哈希表，同空间换时间，时间确实快了，从12ms->4ms
*/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {// 递归分治
        if(input.size() == 0) return {};
        if(hash.count(input) == 1) {// 如果已经有当前解了，直接返回
            return hash[input];
        }
        int index = 0;
        int num = 0;
        while(index < input.size() && isdigit(input[index]))
            num = num * 10 + input[index++] - '0';
        if(index == input.size()){// 如果全是数字
            hash[input] = {num};
            return {num};
        }
        vector<int> ans;
        for(int i = 0; i < input.size(); i++){
            if(isOp(input[i])){
                vector<int> result1 = diffWaysToCompute(input.substr(0,i));
                vector<int> result2 = diffWaysToCompute(input.substr(i+1));
                for(int r1 : result1){
                    for(int r2 : result2){
                        ans.push_back(calculate(r1,input[i],r2));
                    }
                }
            }
        }
        hash[input] = ans;
        return ans;
    }

    bool isOp(const char& c){
        return c == '+' || c == '-' || c == '*';
    }

    int calculate(const int& num1, const char& op, const int& num2){
        if(op == '+')
            return num1 + num2;
        else if(op == '-')
            return num1 - num2;
        else
            return num1 * num2;
    }
private:
    unordered_map<string,vector<int>> hash;
};