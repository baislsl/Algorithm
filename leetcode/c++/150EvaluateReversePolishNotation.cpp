/**
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
	bool isOperator(const string &s) {
		static std::array<string, 4> opers{{"+", "-", "*", "/"}};
		for (auto i = opers.cbegin(); i != opers.cend(); i++) {
			if (s == *i) return true;
		}
		return false;
	}

	int cal(int a, int b, const string &s) {
		switch (s[0]) {
			case '+' :
				return a + b;
			case '-':
				return a - b;
			case '*':
				return a * b;
			case '/' :
				return a / b;
		}
	}

public:
	int evalRPN(vector<string> &tokens) {
		stack<int> stack;
		for (auto &s: tokens) {
			if (isOperator(s)) {
				int a = stack.top();
				stack.pop();
				int b = stack.top();
				stack.pop();
				stack.push(cal(b, a, s));
			} else {
				stack.push(stoi(s));
			}
		}

		return stack.top();


	}
};

int main(){
	vector<string> vs{"2", "1", "+", "3", "*"};
	Solution s;
	cout << s.evalRPN(vs) << endl;
}