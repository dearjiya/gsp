#include <doctest/doctest.h>
#include <iostream>
#include <vector>
#include <map>

namespace
{
struct Entry
{
	std::string name;
	int value;
};
} // namespace

void test(std::vector<int> v, std::vector<int>& rv)
{
	// v is passed by value
	// rv is passed by reference
	v[1] = 99;
	rv[2] = 66;
}

/**
 *
 */
TEST_CASE("Modularity / Function Arguments and Return Values")
{
	/**
	 * usage를 확인한다.  
	 */
	SUBCASE("Argument passing")
	{
		std::vector fib = { 1,2,3,5,8 };
		test(fib, fib);
		std::cout << "----test argument passing----";
		std::cout << fib[1] << ' ' << fib[2] << std::endl;
	}

	/**
	 * auto [n, v]를 포함해서 연습
	 */
	SUBCASE("Structured Binding - user-define struct")
	{
		Entry en;
		en.name = "apple";
		en.value = 2000;

		auto& [n, v] = en;
		n = "banana";
		v = 3000;
		
		std::cout << en.name << " , binding: " << en.value;
	}
	
	SUBCASE("Structured Binding - std::map")
	{
		std::map<int, int> mp;
		// iterator, basic for
		for (std::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
		{
			std::cout << it->first << ' ' << it->second << '\n';
		}

		// auto, enhanced for
		for (auto& i : mp)
		{
			std::cout << i.first << ' ' << i.second << '\n';
		}

		// structured binding, enhanced for
		for (auto& [k, v] : mp)
		{
			std::cout << k << ' ' << v << '\n';
		}

	}
}
