#include <doctest/doctest.h>
#include <iostream>
#include <list>
#include <Header/Vector.h>


namespace
{
class SimpleCopy
{
public: 
	SimpleCopy()
	{
		std::cout << "Default Constructor" << std::endl;
	}

	SimpleCopy(const SimpleCopy& rhs)
	{
		std::cout << "Copy constructor" << std::endl;
	}
};
} // anonymous

TEST_CASE("Essential Operations / Copy and Move")
{
	SUBCASE("test::Vector에 대해 memberwise copy가 문제가 있다는 걸 확인")
	{

	}

	SUBCASE("copy constructor, copy assignment operator를 구현하고 확인")
	{

	}

	SUBCASE("copy constructor 호출 확인")
	{
		SimpleCopy z1;
		SimpleCopy z2 = z1; // == SimpleCopy z2{z1};
	}

	SUBCASE("std::move 구현")
	{
		int v;
		auto rv = std::move(v); // std::move는 레퍼런스를 제거한 타잎의 && 타잎으로 static_cast를 한다. 
	}

	/**
	 * lvalue, xvalue, prvalue를 구분하기
	 */
	SUBCASE("glvalue [lvalue, xvalue], rvalue [xvalue, prvalue]")
	{

	}

	/**
	 * 미묘한 문제를 피하기 
	 * 꼭 해야할 경우 이해하기
	 * essential operation 관점에서만 이해하기.
	 */
	SUBCASE("c++ programmer")
	{
	}
}
