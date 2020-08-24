// https://leetcode-cn.com/problems/word-pattern/

class Solution {
public:
    string getWord(string str, int &i){
        string s = "";
        while(str[i] != ' ' && str[i] != '\0') s += str[i++];
        i++;// 跳过空格
        return s;
    }

    // 还是建立映射关系，alphabet可以用hashset代替
    bool wordPattern(string pattern, string str) {
        unordered_map<string, char> ht;
        vector<bool> alphabet(26, false);
        int wordCount = 0;
        int i = 0;
        while(str[i] == ' ') i++;
        while(i < str.size() && wordCount < pattern.size()){
            string s = getWord(str, i);
            if(ht.find(s) != ht.end()){
                if(ht[s] != pattern[wordCount]) return false;
            }
            else{
                if(alphabet[pattern[wordCount] - 'a']) return false;// 被占用了
                ht[s] = pattern[wordCount];
                alphabet[pattern[wordCount] - 'a'] = true;
            }
            wordCount++;
        }
        if(i < str.size() || wordCount < pattern.size()) return false;// patten长度和word长度不匹配
        return true;
    }
};