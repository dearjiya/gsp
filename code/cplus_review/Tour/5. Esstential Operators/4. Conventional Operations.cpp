#include <doctest/doctest.h>
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

namespace
{
} // anonymous

TEST_CASE("Essential Operations / Conventional Operations")
{
	/**
	 * std::swap()을 vector에 대해 해보고 실제 내부 흐름을 따라가 본다
	 */
	SUBCASE("std::swap 이해하기")
	{
		std::vector<int> v1{ 1, 2, 3 };
		std::vector<int> v2{ 3, 1, 1 };

		std::swap(v1, v2);
	}

	/**
	 * associative container: key, value
	 * c#/python : dictionary
	 * - hash table 
	 * - binary search tree 
	 *   - balanced binary search tree
	 *   - red-black, AVL tree 
	 */
	SUBCASE("std::unordered_map 사용")
	{
		std::unordered_map<int, int> im = { {1, 2} };

		auto v = im[1];
		im.erase(1);
		im.insert({ 2, 3 });
	}
}
