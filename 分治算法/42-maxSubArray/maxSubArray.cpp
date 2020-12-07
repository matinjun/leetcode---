#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
class Solution {
public:
#if 0
    int maxSub(int * a, int i, int j) {
        if(i == j) {
            return a[i];
        } else if(i > j) {
            return 0;
        }
        
        int mid = (i + j) / 2;
        int left_sum = maxSub(a, i, mid);
        int right_sum = maxSub(a, mid + 1, j);

        int mid_sum = a[mid] + a[mid + 1], l = mid - 1, r = mid + 2;
	int tmp = mid_sum;
        while(l >= i) {
            tmp += a[l];
	    if(tmp > mid_sum) mid_sum = tmp;
            --l;
        }
	tmp = mid_sum;
        while(r <= j) {
            tmp += a[r];
	    if(tmp > mid_sum) mid_sum = tmp;
            ++r;
        }

        int max = (left_sum > right_sum ? left_sum : right_sum);
        max = max > mid_sum ? max : mid_sum;

        return max;
    }
    int maxSubArray(vector<int>& nums) {
        int j = nums.size();
        j--;
        return maxSub(nums.data(), 0, j);
    }
#endif

    int maxSubArray(vector<int>& nums) {
	    // 此处使用动态规划，同时使用了一个模板函数max_element()，位于<algorithm>中
	    for(int i = 1; i < nums.size(); ++i) {
		nums[i] += nums[i - 1] > 0 ? (nums[i - 1] + nums[i]) : nums[i - 1];
	    }
	    return *max_element(nums.begin(), nums.end());
    }
};
