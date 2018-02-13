/**
 * There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to
 first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible
 for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0.
 So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0,
 and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices.
 Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
 */


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
		vector<pair<int, vector<int>>> data(numCourses, pair<int, vector<int>>(0, vector<int>()));

		for (auto &p : prerequisites) {
			data[p.first].second.push_back(p.second);
			data[p.second].first++;
		}


		std::queue<unsigned> queue;
		for (unsigned i = 0; i < numCourses; i++) {
			if (data[i].first == 0) {
				queue.push(i);
			}
		}


		int counter = 0;
		while (!queue.empty()) {
			unsigned idx = queue.front();
			queue.pop();
			++counter;

			for (auto next : data[idx].second) {
				data[next].first--;
				if (data[next].first == 0) {
					queue.push(next);
				}
			}
		}

		return counter == numCourses;


	}
};

int main() {
	int num = 2;
	vector<pair<int, int> > pre{
			{1, 0}, {0, 1}
	};
	Solution s;

	cout << std::boolalpha << s.canFinish(num, pre) << endl;
}












