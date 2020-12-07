#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
// we use priority_queue to solve this problem
// you can find its usage on cppreference.com
using Element = pair<string, int>;
class Comp {
public:
    bool operator()(const Element& ele1, const Element& ele2) {
        return (ele1.second < ele2.second) || (ele1.second == ele2.second && ele1.first > ele2.first);
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> table;
	vector<string> ans(k);
        for(string item: words) {
            if(table.find(item) == table.end()) {
                table[item] = 1;
            } else {
                table[item] += 1;
            }
        }

	priority_queue<Element, vector<Element>, Comp> myqueue;

	for(auto item: table) {
		myqueue.push(item);
	}
	for(int i = 0; i < k; ++i) {
		ans[i] = myqueue.top().first;
		myqueue.pop();
	}
	return ans;
		
    }
};
