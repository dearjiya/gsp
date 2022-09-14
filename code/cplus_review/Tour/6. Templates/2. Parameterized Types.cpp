#include <doctest/doctest.h>

#include <vector>

TEST_CASE("Templates / Parameterized Types")
{
	SUBCASE("Vector를 템플릿으로 만들기")
	{
		// template <typename T>
		// class Vector	
	}

	SUBCASE("std::pair와 타잎 추론")
	{
		std::pair<int, double> fd = { 1, 1.5 };
		std::pair fd17 = { 1, 1.5 };
		auto ad = std::make_pair(1, 1.5);
	}
}