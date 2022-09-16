#include <doctest/doctest.h>

#include <vector>
#include <stack>


TEST_CASE("Containers / Vector")
{
	SUBCASE("std::vector를 사용하기")
	{
		std::vector<int> vec;
		vec.push_back(10);
		vec.push_back(20);

		// for(std::vector<int>::size_type i = 0; )
	}

	SUBCASE("c++ iterator")
	{
		// 씹어먹는의 vector의 반복자 연습
	}
}