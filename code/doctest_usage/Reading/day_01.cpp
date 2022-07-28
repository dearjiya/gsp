#include <doctest/doctest.h>
#include <iostream>

namespace foo {
	namespace bar {
		namespace baz {
			int qux = 42;
		}
	}
}

namespace fbz = foo::bar::baz;


TEST_CASE("reading 01")
{
	SUBCASE("std::cout")
	{
		// TODO: cout을 사용하여 출력 
		std::cout << "Hello World" << std::endl;
	}

	SUBCASE("using namespace")
	{
	}

	SUBCASE("namespace alias")
	{
		// https://en.cppreference.com/w/cpp/language/namespace_alias

		CHECK(fbz::qux == 42);
	}

	SUBCASE("for")
	{
		int i, sum = 0;
		for (i = 0; i < 10; i++)
		{
			sum += i;
		}
		std::cout << "합은: " << sum << std::endl;
		CHECK(sum == 19);
	}

	SUBCASE("while")
	{
		int i = 1, sum = 0;
		while (i <= 10)
		{
			sum += i;
			i++;
		}

		CHECK(sum == 45);

	}

	SUBCASE("if")
	{
		int num = 5;
		bool result = false;
		if (num == 5)
		{
			result = true;
		}
		else
		{
			result = false;
		}
		CHECK(result);

	}

	SUBCASE("switch")
	{
		int age = 30;

		switch (age)
		{
		case 1:

		}

	}
}