// https://leetcode-cn.com/problems/utf-8-validation/

class Solution {
private:
    int char_bytes = 0;  // 统计当前字符有多少位，0,2,3,4有效
public:
    // 统计一个数字开头有多少个1，既可以用于统计编码字节数，又可以用于统计当前数字是否满足10
    void get_char_bytes(int cur_num, int& char_bytes) {
        while (cur_num & 0x80) {
            char_bytes++;
            cur_num = cur_num << 1;
        }
    }

    bool validUtf8(vector<int>& data) {
        int i;

        for (i = 0; i < data.size(); i++) {
            int one_cnt = 0;
            int cur_data = data[i];
            if (char_bytes) {
                get_char_bytes(cur_data, one_cnt);  // 统计当前数字是否满足10
                if (one_cnt != 1) {
                    return false;
                }
                char_bytes--;
            } else {  // 说明遇到一个新字符，统计字符字节数
                get_char_bytes(cur_data, char_bytes);
                if (char_bytes == 1 || char_bytes > 4) {
                    return false;// 对于 1 字节的字符，字节的第一位设为 0，后面 7 位为这个符号的 unicode 码。
                }
                char_bytes = char_bytes == 0 ? 0 : char_bytes - 1;  // 除了第一个数字之外，还需要校验n - 1个数字
            }
        }
        return char_bytes == 0;
    }
};