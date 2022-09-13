#include <doctest/doctest.h>
#include <iostream>
#include <list>
#include <vector>


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
}
