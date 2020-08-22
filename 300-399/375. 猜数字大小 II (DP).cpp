// https://leetcode-cn.com/problems/guess-number-higher-or-lower-ii/
/*我们正在玩一个猜数游戏，游戏规则如下：

我从 1 到 n 之间选择一个数字，你来猜我选了哪个数字。

每次你猜错了，我都会告诉你，我选的数字比你的大了或者小了。

然而，当你猜了数字 x 并且猜错了的时候，你需要支付金额为 x 的现金。直到你猜到我选的数字，你才算赢得了这个游戏。*/
/*
| 0 1 x x |  dp[1][4]计算步骤向上看
| \ 0 2 x |  dp[2][4]计算步骤向上看(然后填充)
| \ \ 0 x |  dp[3][4]计算步骤向上看(先填充)
| \ \ \ 0 |
只需要算上三角*/
class Solution {
public:
    int getMoneyAmount(int n) {
        if(n==1)
            return 0;
        //定义矩阵
        int dp[n+1][n+1];// dp[i][j]是说依次以从i到j的数字作为分割点(猜的数)，必定赢的游戏所用钱的最小值。
        //初始化“\”
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=INT_MAX;
            }
        }
        //定义基础值dp[i][i]
        for(int i=0;i<=n;i++){// 只有一个就不用猜，肯定是0
            dp[i][i]=0;
        }

        //按列来，从第2列开始
        for(int j=2;j<=n;j++){
            //按行来，从下往上
            for(int i=j-1;i>=1;i--){
                //计算除了两端的每一个分割点
                for(int k=i+1;k<=j-1;k++){
                    dp[i][j]=min(k+max(dp[i][k-1],dp[k+1][j]),dp[i][j]);// 其中max是为了这一步猜错后，“保证能赢”，取多的那一部分
                }
                // 算两端，这些取min代表在所有保证赢的情况下，花费的钱最少
                dp[i][j]=min(dp[i][j],i+dp[i+1][j]);// 猜i
                dp[i][j]=min(dp[i][j],j+dp[i][j-1]);// 猜j
            }
        }
        return dp[1][n];
    }
};