#include <doctest/doctest.h>
#include <iostream>
#include <vector>

namespace jiya
{
template<int N>struct Check
{
};

constexpr int add(int a, int b)
{
	return a + b;
}
}

TEST_CASE("Basics / Constants")
{
	SUBCASE("constexpr")
	{
		constexpr int dmv = 17;
		int var = 17;
		const double sqv = sqrt(var);

		constexpr int number = 3;
		enum B {x = number, y, z};
		std::cout << B::x << "," << B::y << "," << B::z << std::endl;
	}

	/**
	 * 언제 constexpr로 동작해서 계산이 되는 지, 언제 실행시간에 계산 하는 지
	 * 실험을 간단하게 해보면 좋을 듯 하다.
	 */
	SUBCASE("constexpr function")
	{
		int n1 = 1;
		int n2 = 2;

		int n = jiya::add(n1, n2);
		int m = jiya::add(1, 2);
		jiya::Check<jiya::add(1, 2)> c;
		//jiya::Check<jiya::add(n1, n2)> c2;
	}


	SUBCASE("constant expression을 필요로 하는 경우")
	{
		int a[3]; // 3이 constexpr이다. 

	}
}