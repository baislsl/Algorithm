/**
 * Sort a linked list in O(n log n) time using constant space complexity.
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;

	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode *sortList(ListNode *head) {
		ListNode *l1, *l2;
		l1 = head;

		// find l2
		int counter = 0;
		ListNode *p1, *p2;
		p1 = p2 = head;
		while (p1 != nullptr) {
			++counter;
			p1 = p1->next;
			if (counter % 2 == 0) p2 = p2->next;
		}

		if (counter < 2) return head;
		if(counter == 2){
			auto p1 = head, p2 = head->next;
			if(p1->val < p2->val) std::swap(p1, p2);
			p2->next = p1;
			p1->next = nullptr;
			return p2;
		}


		l2 = p2->next;
		p2->next = nullptr;
		l1 = sortList(l1);
		l2 = sortList(l2);
//		for(auto p = l1; p ; p = p->next) {cout << p->val << " ";} cout << endl;
//		for(auto p = l2; p ; p = p->next) {cout << p->val << " ";} cout << endl;

		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;

		if (l1->val > l2->val) std::swap(l1, l2);
		ListNode *cur1 = l1, *preCur = l1->next;
		ListNode *cur2 = l2;
		while (cur2 != nullptr && cur1 != nullptr) {
			while (cur1 != nullptr && (preCur == nullptr || cur2->val > preCur->val)){
				cur1 = cur1->next;
				if(preCur != nullptr) preCur = preCur->next;
			}
			if (cur1 != nullptr) {
				auto temp = cur2->next;
				cur2->next = cur1->next;
				cur1->next = cur2;
				preCur = cur2;
				cur2 = temp;
			}
		}

		if (cur2 == nullptr) return l1;

		// cur1 == nullptr
		for (cur1 = l1; cur1->next != nullptr; cur1 = cur1->next) {}
		cur1->next = cur2;
		return l1;

	}
};

int main() {
	vector<ListNode> nodes{2, -10, 5, 7, 1, 8};
	for(int i = 0; i < nodes.size() - 1; i++){
		nodes[i].next = &nodes[i + 1];
	}
	nodes[nodes.size() - 1].next = nullptr;

	Solution s;
	auto ans = s.sortList(&nodes[0]);
	while (ans != nullptr){
		cout << ans->val << " ";
		ans = ans->next;
	}

}
