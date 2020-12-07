#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, bool> table;
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> line(3);

        if(!n) return ans;
        sort(nums.begin(), nums.end());
        for(auto item: nums) {
            table[item] = true;
        }
        // 采用双指针法
        // 此处有错误
        for(int i = 0; i < n && nums[i] <= 0; ++i) { 
            for(int j = i + 1; j < n - 1; ++j) {
                int tmp = (-nums[i] - nums[j]);
                if(tmp >= nums[j + 1] && table.count(tmp) > 0) {
                    line[0] = nums[i];
                    line[1] = nums[j];
                    line[2] = -nums[i] -nums[j];
                    ans.push_back(line);
                }
            }
        }
        return ans;
    }
};
