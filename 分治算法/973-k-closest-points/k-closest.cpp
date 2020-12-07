#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class Comp {
public:
    vector<vector<int>> points;
    Comp(const vector<vector<int>>& _points) : points(_points) {}
    bool operator()(int x, int y) {
        // 如果x对应的点小于y对应的点，返回正确
        return points[x][0] * points[x][0] + points[x][1] * points[x][1] 
            < points[y][0] * points[y][0] + points[y][1] * points[y][1];
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
#if 0
	    // 使用优先队列，会时间超限
        Comp comp(points);
        // 定义一个优先队列，存当前前面k个点
        priority_queue<int, vector<int>, Comp> p_queue(points);
        for(int i = 0; i < K; ++i) {
            p_queue.push(i);
        }
	// 每次更新最前面的k个点，确保前面k个点最近
        for(int i = K; i < points.size(); ++i) {
		// 将当前点与最大点比较
            if(comp(i, p_queue.top())) {
                p_queue.pop();
                p_queue.push(i);
            }
        }
        vector<int> point(2);
        vector<vector<int>> ans(K, point);
        for(int i = 0; i < K; ++i) {
            ans[i] = points[p_queue.top()];
            p_queue.pop();
        }
        return ans;
#endif
	// 使用快速排序
	sort(points.begin(), points.end(), [](vector<int>& p1, vector<int>& p2) {return p1[0]*p1[0]+p1[1]*p1[1] < p2[0]*p2[0]+p2[1]*p2[1];});
	points.resize(K);
	return points;
    }
};
