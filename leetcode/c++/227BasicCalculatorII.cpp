/**
 * Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
	string removeBreak(const string &s) {
		string ans;
		for (char cc : s) {
			if (cc != ' ')
				ans += cc;
		}
		return ans;
	}

	struct Node {
		bool isNum;
		int val;
		string oper;

		Node *parent, *left, *right;

		explicit Node(int val) : val(val), isNum(true), oper(""), parent(nullptr), left(nullptr), right(nullptr) {}

		explicit Node(const string &oper) : oper(oper), isNum(false), parent(nullptr), left(nullptr), right(nullptr) {}

		Node *getRoot() {
			Node *ans = this;
			while (ans->parent != nullptr) ans = ans->parent;
			return ans;
		}

	};

	int calculate(Node *root) {
		if (root->isNum) return root->val;
		int left = calculate(root->left);
		int right = calculate(root->right);

		switch(root->oper[0]) {
			case '+':
				return left + right;
			case '-':
				return left - right;
			case '*':
				return left * right;
			case '/':
				return left/right;
		}




	}

public:
	int calculate(string s) {
		s = removeBreak(s);
		vector<Node> nodes;

		string num = "";
		for (size_t i = 0; i < s.length(); i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				num += s[i];
			} else {
				nodes.emplace_back(Node(std::stoi(num)));
				nodes.emplace_back(Node(string(1, s[i])));
				num = "";
			}
		}
		nodes.emplace_back(Node(std::stoi(num)));
		size_t n = nodes.size();

		for (size_t i = 0; i < n; i++) {
			if (nodes[i].oper == "/" || nodes[i].oper == "*") {
				Node *left = nodes[i - 1].getRoot();
				Node *right = nodes[i + 1].getRoot();
				left->parent = right->parent = &nodes[i];
				nodes[i].left = left;
				nodes[i].right = right;
			}
		}

		for (size_t i = 0; i < n; i++) {
			if (nodes[i].oper == "-" || nodes[i].oper == "+") {
				Node *left = nodes[i - 1].getRoot();
				Node *right = nodes[i + 1].getRoot();
				left->parent = right->parent = &nodes[i];
				nodes[i].left = left;
				nodes[i].right = right;
			}
		}

		Node *root = nodes[0].getRoot();
		return calculate(root);
	}
};


int main() {
	Solution s;
	cout << s.calculate(" 3+5 / 2 ") << endl;
	cout << s.calculate("3 +2*2-8/3") << endl;
	cout << s.calculate("42") << endl;

}
