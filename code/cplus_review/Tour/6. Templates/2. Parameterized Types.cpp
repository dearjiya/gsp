#include <doctest/doctest.h>

#include <vector>

TEST_CASE("Templates / Parameterized Types")
{
	SUBCASE("Vector�� ���ø����� �����")
	{
		// template <typename T>
		// class Vector	
	}

	SUBCASE("std::pair�� Ÿ�� �߷�")
	{
		std::pair<int, double> fd = { 1, 1.5 };
		std::pair fd17 = { 1, 1.5 };
		auto ad = std::make_pair(1, 1.5);
	}
}