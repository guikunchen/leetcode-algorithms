#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/simplify-path/

class Solution {
public:
    // C++利用stringstream和getline分割字符串
    vector<string> split(const string& s,char delemiter){
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while(getline(tokenStream,token,delemiter)){
            if(token == "" || token == "." || (token == ".." && tokens.size() == 0))
                continue;
            else if(token == ".." && tokens.size() > 0)
                tokens.pop_back();
            else
                tokens.push_back(token);
        }
        return tokens;
    }
    string simplifyPath(string path) {
        string str= "";
        vector<string> tmp = split(path,'/');
        for(auto s:tmp){
            str+="/";
            str+=s;
        }
        return str == "" ? "/" : str;
    }
};