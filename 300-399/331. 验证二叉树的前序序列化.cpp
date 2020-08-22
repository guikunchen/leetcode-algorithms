#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/

class Solution {
public:

    //分割数组 注：strtok会改变原字符串
    vector<string> split(string& s, const char* delim)
    {
        vector<string> v;
        char* str = strtok((char*)s.c_str(), delim);
        while (str)
        {
            v.push_back(string(str));
            str = strtok(NULL, delim);
        }
        return v;
    }

    //1、时间复杂度O(N) 空间复杂度O(N)
    bool isValidSerialization(string preorder) {

        int slots = 1;// 初始槽位只有一个

        for (const string& node : split(preorder, ","))
        {
            --slots;// 空节点和非空节点都消耗一个槽位

            if (slots < 0) //本不应该再有槽了 但preorder出现了多的槽
            {
                return false;
            }

            if (node != "#") // 非空节点增加槽位
            {
                slots += 2;
            }
        }

        return slots == 0;
    }


    //2、不分割数组 直接遍历preorder  时间复杂度O(N) 空间复杂度O(1)
    bool isValidSerialization(string preorder) {

        if (preorder.empty())
        {
            return false;
        }

        int slots = 1;

        for (int i = 0; i < preorder.size() - 1; ++i)
        {
            //如果下一个是',' 则slots减一
            if (preorder.at(i + 1) == ',')
            {
                --slots;
                if (slots < 0)
                {
                    return false;
                }

                if (preorder.at(i) != '#') //是数字
                {
                    slots += 2;
                }
            }
            
        }

        //最后一个元素 没有下一个","了 需要单独处理 
        --slots;
        if (preorder.back() != '#') //最后一个是数字
        {
            slots += 2;
        }

        return slots == 0;
    }
};