#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/additive-number/
class Solution {
public:
    bool isAdditiveNumber(string num) {// 总共三个数不断迭代
        int i=0;
        for(int j=i+1;j<=num.size()-1;j++){
            for(int k=j+1;k<=num.size()-1;k++){// 遍历j k所有可能的位置，其实j最多只能取到 n/2
                if(dfs(num,i,j,k)) return true;
            }
        }
        return false;
    }

    bool dfs(string& s,int i,int j,int k){// i j k是三个数的起始索引
        if((s[i]=='0'&&j-i>1)||(s[j]=='0'&&k-j>1)) return false;// 开头为0长度大于1的数，不可能
        string a=s.substr(i,j-i);
        string b=s.substr(j,k-j);
        string sum=add(a,b);
        int n=sum.size();
        if(k+n-1>s.size()-1 || sum!=s.substr(k,n)) return false;// 长度超过，或加法和不相等
        if(k+n-1==s.size()-1) return true;// 加法和相等，k+n就是最后一个数
        return dfs(s,j,k,k+n);
    }

    string add(string& a,string& b){// 大数加法
        int n1=a.size()-1;
        int n2=b.size()-1;
        int carry=0;
        string ans;
        while(n1>=0||n2>=0||carry>0){
            int t1=n1>=0?a[n1--]-'0':0;
            int t2=n2>=0?b[n2--]-'0':0;
            ans+=(t1+t2+carry)%10+'0';
            carry=(t1+t2+carry)>=10?1:0;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};