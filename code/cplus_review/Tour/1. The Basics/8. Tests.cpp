#include <doctest/doctest.h>
#include <iostream>
#include <vector>

TEST_CASE("Basics / Tests")
{
	/**
	 * 특별한 것은 없지만 break, default 사용을 간단하게 연습
	 */
	SUBCASE("switch")
	{

	}

	/**
	 * if 문 안에서 선언을 사용하는 것
	 */
	SUBCASE("if")
	{
		if (auto s = 0; false)
		{
		} 
	}
}
