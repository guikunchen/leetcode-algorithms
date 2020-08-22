#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/count-of-range-sum/

// 前缀和+离散化(排序, 去重, 建立数值和下标[1,n]的映射)+树状数组   
// 我们定义前缀和数组, sum[i]为nums[0,i)的和, 左闭右开, 所以有sum[0]=0.
    // 如果区间[i,j]的和sum[j+1]-sum[i]在[lower, upper]之间, 我们通过移项可以得到sum[j+1]−upper<=sum[i]<=sum[j+1]−lower
    // 固定j/j+1, 我们只需要看前面有多少个sum[i]在sum[j+1]−upper和sum[j+1]−lower之间即可 =>  树状数组
// 我们用一个非常大的树状数组来记录截止目前, 某个sum[i]值的个数. 
    // find(sum[j+1]−lower) - find(sum[j+1]−upper -1)就可以得到有多少个符合条件的i. 
        //注意sum[j+1]−upper -1, 为什么要多减去1个1, 因为上面是<=, 包括=sum[j+1]−upper的情况, 所以我们要再取小一点点.
// 接下来的问题是, sum的值可能为负, 也可能很大, 所以我们必须 => 离散化
    // 我们涉及到add(sum[i], 1 )的操作, 涉及到find(sum[j+1]−lower)的操作, 所以我们要离散化sum, sum-lower,sum-upper
        // 实际上并不需要查找sum−upper -1, 我们获得sum-upper的离散化排名后, 直接把排名-1即可
            // 所以在离散化建立映射的时候, 我们要把最小的那个数对应的排名设置得大一点, 不要设置为1 , 设置为2/3/....
// 另外, 我们特别要注意, 一定要提前在树状数组里设置好0对应的位置为1; 所以在之前离散化的时候, 我们也要把0作为sum的一员

typedef long long LL;
class Solution {
public:
    
    vector<LL> data; // 记录前缀和,前缀和-lower, 前缀和-upper; 再排序, 去重
    vector<int> tr; // 树状数组使用的数组, 以某种方式记录着某个数值的出现次数
    unordered_map<LL, int> m; // 记录数值到下标的映射
    
    // 树状数组需要的工具函数
    int lowbit(int x) { //只保留最低位的1
        return x & -x; 
    }
    
    int find(int x) { //计算[1,x]位置上所有数的和
        int ans = 0;
        for (int i = x; i; i -= lowbit(i)) ans += tr[i];
        return ans;
    }
    
    void add(int x, int c) { // 位置x对应的数增加了c
        int n = tr.size() - 1;
        for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        data=vector<LL>( 3*(n+1), 0); // 记录所有的前缀和, 前缀和-lower, 前缀和-upper
        for(int i=0; i<n; ++i)
            data[i+1]=data[i]+nums[i];
        for(int i=0; i<=n;++i){
            data[n + 2*i+1]=data[i]-lower;
            data[n + 2*i+2]=data[i]-upper;
        }

        // 排序
        sort(data.begin(), data.end());
        // 去重
        data.erase(unique(data.begin(), data.end()), data.end());

        for(int i=0;i<data.size(); ++i) // 生成排名, 注意排名本来就需要从1开始; 但是由于我们有的时候需要把排名-1, 所以让排名从2开始
            m[data[i]] = i+2;
        
        tr = vector<int>(data.size()+2,0); // 树状数组只记录前缀和，离散化的时候离散化了三种
        add(m[0], 1); // 一定要注意, 一定要把0先加进去

        int res=0; LL sum=0;
        for(int i=0;i<nums.size();++i) {
            sum += nums[i]; // 前缀和
            int b = find(m[sum-lower]); // 寻找截止目前小于等于sum-lower的有多少个
            int a = find(m[sum-upper]-1); // 寻找截止目前小于sum-upper的有多少个; 注意我们把排名-1后再使用
            res += b-a; // 二者之差即为符合条件的i的个数
            add(m[sum], 1); // 增加上去
        }
        return res;
    }
};