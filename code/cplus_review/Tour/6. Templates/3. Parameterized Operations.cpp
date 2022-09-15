#include <doctest/doctest.h>

#include <numeric>
#include <vector>

TEST_CASE("Templates / Parameterized Operations")
{
	SUBCASE("std::accumulate 사용")
	{
		auto vs = std::vector<int>{ 1, 2, 3 };
		// auto v = std::accumulate(vs.begin(), vs.end(), std::plus());
	}

	SUBCASE("Less_than 구현과 사용")
	{
		// lti(3);
		// lti(43);


	}

	SUBCASE("lambda의 사용")
	{

	}
}