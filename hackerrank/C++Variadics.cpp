#include <iostream>

using namespace std;

template<bool ... digits>
struct helper;

template<>
struct helper<> {
	constexpr static int value = 0;
};

template<bool f, bool ... digits>
struct helper<f, digits...> {
	constexpr static int value = helper<digits...>::value * 2 + (f ? 1 : 0);
};

template<bool... digits>
constexpr int reversed_binary_value() {
	return helper<digits...>::value;
}

template<int n, bool...digits>
struct CheckValues {
	static void check(int x, int y) {
		CheckValues<n - 1, 0, digits...>::check(x, y);
		CheckValues<n - 1, 1, digits...>::check(x, y);
	}
};

template<bool...digits>
struct CheckValues<0, digits...> {
	static void check(int x, int y) {
		int z = reversed_binary_value<digits...>();
		std::cout << (z + 64 * y == x);
	}
};

int main() {
	static_assert(reversed_binary_value<0, 0, 1>() == 4);
	static_assert(reversed_binary_value<0, 1, 1>() == 6);
	int t;
	std::cin >> t;

	for (int i = 0; i != t; ++i) {
		int x, y;
		cin >> x >> y;
		CheckValues<6>::check(x, y);
		cout << "\n";
	}
}



