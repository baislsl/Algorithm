#include <vector>
#include <iostream>

#include <tuple>

template<typename>
struct is_data : std::false_type {
};

template<>
struct is_data<int> : std::true_type {
};
template<>
struct is_data<double> : std::true_type {
};
template<>
struct is_data<float> : std::true_type {
};
template<>
struct is_data<long> : std::true_type {
};
template<>
struct is_data<unsigned> : std::true_type {
};
template<>
struct is_data<long long> : std::true_type {
};


template<size_t N = 0, typename... T>
struct helper {
	template<typename ...Ts>
	double func(const std::tuple<Ts...> &tpl);
};


template<size_t N>
struct helper<N> {
	template<typename ...Ts>
	static double func(const std::tuple<Ts...> &tpl) {
		return 0.0;
	};
};

template<bool, size_t N, typename... Ts>
struct type_helper;

template<size_t N, typename... Ts>
struct type_helper<false, N, Ts...> {
	static double func(const std::tuple<Ts...> &tpl){
		return 0.0;
	}
};

template<size_t N, typename... Ts>
struct type_helper<true, N, Ts...> {
	static double func(const std::tuple<Ts...> &tpl){
		return static_cast<double >(std::get<N>(tpl	));
	}
};


template<size_t N, typename T, typename... Ts>
struct helper<N, T, Ts...> {
	template<typename ...Ts2>
	static double func(const std::tuple<Ts2...> &tpl) {
		return type_helper<is_data<T>::value, N, Ts2...>::func(tpl) + helper<N + 1, Ts...>::func(tpl);
	}

};


template<size_t N, typename... Ts>
constexpr double func(const std::tuple<Ts...> &tpl) {
	double result = 0;
	if constexpr (N < sizeof...(Ts)) {
		auto ele = std::get<N>(tpl);
		if constexpr (is_data<decltype(ele)>::value) {
			result += static_cast<double>(ele);
		}
		result += func<N + 1, Ts...>(tpl);
	}
	return result;
}


template<typename... Ts>
constexpr double tuple_sum(const std::tuple<Ts...> &tpl) {
	return helper<0, Ts...>::func(tpl);
}

int main() {
	char g = 'f';
	auto gg = std::make_tuple(&g, 3.14, 42, 'a', "Hello", "World", std::vector<int>{1, 2, 3});
	std::cout << tuple_sum(gg);
}




