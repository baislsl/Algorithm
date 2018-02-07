

#include <bits/stdc++.h>

using namespace std;

#define MAXN 50010

int pre[MAXN], ino[MAXN];

struct Node {
	Node *left, *right;
	int val;

	Node() : val(0), left(nullptr), right(nullptr) {}
};

Node *readin(int &pbegin, int &pend, int &ibegin, int &iend, int err = -1) {
	if (pbegin == pend || ibegin == iend) return nullptr;
	if(err != -1 && ino[ibegin] == err) return nullptr;
	Node *node = new Node();
	node->val = pre[pbegin];
	int midEnd = -1;
	for (int i = ibegin; i < iend; i++) {
		if (ino[i] == node->val){
			midEnd = i;
			break;
		}
	}
	if (midEnd == -1) { while (1) {}};

//	node->left = readin(++pbegin, pend, ibegin, iend, node->val);
	 node->left = readin(++pbegin, pend, ibegin, midEnd);
	node->right = readin(pbegin, pend, ++ibegin, iend);
	return node;
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", pre + i);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", ino + i);
	}
	int pbegin = 0, pend = n, ibegin = 0, iend = n;
	Node *root = readin(pbegin, pend, ibegin, iend);
	while (root->left != nullptr || root->right != nullptr) {
		if (root->left != nullptr) {
			root = root->left;
		} else {
			root = root->right;
		}
	}

	cout << root->val << endl;

}

