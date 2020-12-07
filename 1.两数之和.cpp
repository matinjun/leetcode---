/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> result(2);
        // for(int i = 0; i < nums.size(); ++i) {
            // for(int j = i + 1; j < nums.size(); ++j) {
                // if(nums[i] + nums[j] == target) {
                    // result[0] = i;
                    // result[1] = j;
                    // break;
                // }
            // }
        // }
        // return result;
        unordered_map<int, int> hashtable;
        for(int i = 0; i < nums.size(); ++i) {
            if(hashtable.find(target - nums[i]) != hashtable.end()) {
                return {i, hashtable[target - nums[i]]};

            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

