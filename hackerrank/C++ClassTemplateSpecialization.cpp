#include <iostream>

using namespace std;
enum class Color {
	red, green, orange
};
enum class Fruit {
	apple, orange, pear
};

template<typename T>
struct Traits;

// Define specializations for the Traits class template here.
template<>
struct Traits<Color> {
	static string name(const int i) {
		static string ss[] = {"red", "green", "orange"};
		if (i >= 3 || i < 0) return "unknown";
		return ss[i];
	}
};


template<>
struct Traits<Fruit> {
	static string name(const int i) {
		static string ss[] = {"apple", "orange", "pear"};
		if (i >= 3 || i < 0) return "unknown";
		return ss[i];
	}
};

int main() {
	int t = 0;
	std::cin >> t;

	for (int i = 0; i != t; ++i) {
		int index1;
		std::cin >> index1;
		int index2;
		std::cin >> index2;
		cout << Traits<Color>::name(index1) << " ";
		cout << Traits<Fruit>::name(index2) << "\n";
	}
}
