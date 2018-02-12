/**
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or ..
 A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
 */

#include <bits/stdc++.h>

using namespace std;
class WordDictionary {
private:

	class Node {
	public:
		int ele;
		bool flag;
		Node *next[26];

		Node() : flag(false) {
			for(auto &p : next)
				p = nullptr;
		}
	};

	Node root;

	bool match(Node *cur, string::const_iterator obj, string::const_iterator end) {
		if(cur == nullptr){
			return false;
		}
		if(obj == end) return cur->flag;
		if (*obj == '.') {
			++obj;
			for(Node* n : cur->next){
				if(n != nullptr && match(n, obj, end)) return true;
			}
			return false;
		} else {
			int k = *obj - 'a';
			++obj;
			return match(cur->next[k], obj, end);
		}
	}

public:
	/** Initialize your data structure here. */
	WordDictionary() : root() {
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		Node *cur = &root;
		for (const char cc : word) {
			if (cur->next[cc - 'a'] == nullptr)
				cur->next[cc - 'a'] = new Node();
			cur = cur->next[cc - 'a'];
		}
		cur->flag = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return match(&root, word.cbegin(), word.cend());
	}
};


int main() {
	WordDictionary dict;
	dict.addWord("bad");
	dict.addWord("dad");
	dict.addWord("mad");
	cout << std::boolalpha << dict.search("pad") << " "
		 << dict.search("bad")  << " "
		 << dict.search(".ad")  << " "
		 << dict.search("b..")  << " "
		 << endl;

}



