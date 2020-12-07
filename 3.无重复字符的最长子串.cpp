/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.length()) return 0;
        // nearest表示离当前字母最近的前一个字母的位置
        unordered_map<char, int> nearest;
        // maxLength表示以当前字符串为末尾的最长无重复字符的子字符串长度
        vector<int> maxLength(s.length());
        int maxIndex = 0;
        maxLength[0] = 1;
        nearest[s[0]] = 0;
        for(int i = 1; i < s.length(); i++) {
            // 如果当前字符没在前面的子串中出现，长度就加一
            if(nearest.find(s[i]) == nearest.end() 
                || nearest[s[i]] < i - maxLength[i - 1]) {
                maxLength[i] = 1 + maxLength[i - 1];
            } else {
                // 反之使用当前字符最近一次出现的位置计算
                maxLength[i] = i - nearest[s[i]];
            }
            // 更新字符最近出现位置
            nearest[s[i]] = i;
            if(maxLength[i] > maxLength[maxIndex]) {
                maxIndex = i;
            }
        }
        return maxLength[maxIndex];
    }
};
// @lc code=end

