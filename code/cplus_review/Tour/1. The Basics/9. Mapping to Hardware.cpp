#include <doctest/doctest.h>
#include <iostream>
#include <vector>

TEST_CASE("Basics / Mapping to Hardware")
{
	/**
	 * 여러 오브젝트에 대한 포인터가 어떤 주소를 갖는 지, 어떻게 분포되는 지 살펴본다.
	 */
	SUBCASE("pointer to object and address")
	{
		char* p = new char[2];
		char v;
		char* p2 = &v;
	}

	SUBCASE("assignment")
	{
		int x = 2;
		int y = 3;

		y = x;
	}

	SUBCASE("accessing uninitialized object")
	{
		// int& r2;
		// r2 = 99;
	}
}
