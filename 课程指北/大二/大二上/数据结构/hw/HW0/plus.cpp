#include<cstdio>
#include <chrono>
#include <iostream>

auto start = std::chrono::system_clock::now();
//do something
auto end = std::chrono::system_clock::now();
auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

int main() {
	auto start = std::chrono::system_clock::now();
	long long a, b;
	std::scanf("%lld%lld", &a, &b);
	std::printf("%lld\n", a + b);
	auto end = std::chrono::system_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << elapsed.count() << "ms" << '\n';
	return 0;
}