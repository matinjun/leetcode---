#include <iostream>
#include <algorithm>
#include <iterator>
#include <new>
#include <vector>

using namespace std;
/* 1. 对每行采用二分查找，效率较低
 * 2. 使用分治，降低复杂度*/
class Solution {
	public:
		bool searchMatrix(vector<vector<int>>& matrix, int target) {
#if 0
			// 1
			bool ans = false;
			for(int i = 0; i < matrix.size(); ++i) {
				int s = 0, e = matrix[i].size() - 1;
				int mid;
				while(s <= e) {
					mid = (s + e) / 2;
					if(matrix[i][mid] == target) {
						break;
					} else if(matrix[i][mid] < target) {
						s = mid + 1;
					} else {
						e = mid - 1;
					}
				}
				ans = ans || (s <= e);
			}						
			return ans;	
#endif
			int i = matrix.size() - 1, j = 0;
			if (!matrix.size() || !matrix[0].size()) {
				return false;
			}

			while(i >= 0 && j < matrix[0].size()) {
				if(target < matrix[i][j]) {
					--i;
				} else if(matrix[i][j] < target) {
					++j;
				} else {
					return true;
				}
			}
			return false;
		}
};
