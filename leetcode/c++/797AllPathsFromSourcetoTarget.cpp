#include "leetcode.h"


class Solution {
private:
	void dfs(int cur, int n, const vector<vector<int> > &graph, vector<vector<int> > &ans, vector<int> path) {
		path.push_back(cur);
		if (cur == n - 1) {
			ans.push_back(path);
			return;
		}
		for (int i : graph[cur]) {
			dfs(i, n, graph, ans, path);
		}
		// path.erase(++path.rbegin());

	}

public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
		int n = graph.size();
		vector<vector<bool> > mat(n, vector<bool>(n, false));
//
//		for (int i = 0; i < n; i++) {
//			for (int j : graph[i]) {
//				mat[i][j] = true;
//			}
//		}


		vector<vector<int>> ans;
		vector<int> path;

		dfs(0, n, graph, ans, path);


		return ans;
	}
};


int main() {
	vector<vector<int>> graph {{
									   {1, 2},
									   {3},
									   {3},
									   {}
							   }};

	Solution s;
	auto ans = s.allPathsSourceTarget(graph);
	for(auto& v: ans) {
		for(int i : v) {
			cout << i << " ";
		}
		cout << endl;

	}

}
