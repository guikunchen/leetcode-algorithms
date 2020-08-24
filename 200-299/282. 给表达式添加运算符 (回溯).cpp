#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/expression-add-operators/
/*给定一个仅包含数字 0-9 的字符串和一个目标值，在数字之间添加二元运算符（不是一元）+、- 或 * ，返回所有能够得到目标值的表达式。

示例 1:

输入: num = "123", target = 6
输出: ["1+2+3", "1*2*3"] 
示例 2:

输入: num = "232", target = 8
输出: ["2*3+2", "2+3*2"] */


typedef long long LL;
class Solution {
public:
    vector<string> res;
    string path;
    vector<string> addOperators(string num, int target) {
        if(num == ""){
            return {};
        }
        backtrack(0,0,1,num[0] - '0',1,num.size(),target,num);
        return res;
    }
// 在回溯中引入四个变量pre，left，operand和sign其中pre和left功能类似，
// pre保存整个表达式自左向右运算时的结果，而left保存其中某段乘法表达式自左向右运算的结果，
// 而operand是在当前形成的操作数，sign记录添加的是正号还是负号。算法分以下四种情况进行搜索和回溯：
    void backtrack(int idx,LL pre,LL left,LL operand,int sign,int n,int target,string& num){
        //查看串尾是否运算符来判断当前数字是否操作数的首位
        bool isBeg = path.empty() || path.back() < '0'; 

        path += num[idx];// 数字加到路径末尾
        if(idx == n - 1){// 遍历到字符串最后一个位置
            if(pre + sign * left * operand == target){// 如果等于target
                res.emplace_back(path);
            }
        }else{
            int next_num = num[idx + 1] - '0';
            string old_path = path;
            //追加数字时不能形成有前导0的情况
            if(!(isBeg && num[idx] == '0')){// 当前数字不能既是0又是一个操作数的首位置
                backtrack(idx + 1,pre,left,operand * 10 + next_num,sign,n,target,num);
                path = old_path;
            }
            path += '+';// 添加的是操作数和正号：添加正号在后面不会改变优先级，可以将当前操作数（其符号是上一层添加的）更新到pre，pre += sign * operand，进入下一层搜索。

            backtrack(idx + 1,pre + sign * left * operand,1,next_num,1,n,target,num);
            path = old_path;

            path += '-';// 添加的是操作数和负号：添加负号在后面不会改变优先级，和正数一样，更新pre，进入下一层搜索。
            backtrack(idx + 1,pre + sign * left * operand,1,next_num,-1,n,target,num);  
            path = old_path;

            path += '*';// 添加的是操作数和乘号：添加乘号会改变运算优先级，所以不能立刻更新pre，而是需要先完成后续的乘法运算先。乘法运算维护一个累计值left，在一段乘法运算中不断更新left，直到下一个加入的符号是加号或减号，乘法结束，可以更新pre，即pre += sign * left * operand，添加乘号不会改变运算正负，故一直保存的符号是上一个正负号直到乘法完成。
            backtrack(idx + 1,pre,left * operand,next_num,sign,n,target,num);
        }
    }
};