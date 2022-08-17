#include <doctest/doctest.h>
#include <iostream>

namespace foo {
	namespace bar {
		namespace baz {
			int qux = 42;
		}
	}
}
namespace foo2
{
	int qux = 32;
}

namespace fbz = foo::bar::baz;


TEST_CASE("reading 01")
{
	SUBCASE("std::cout")
	{
		// TODO: cout을 사용하여 출력 
		//std::cout << "Hello World" << std::endl;
	}

	SUBCASE("using namespace")
	{
		auto rv = foo2::qux == 42;
		CHECK(!rv);
	}

	SUBCASE("namespace alias")
	{
		// https://en.cppreference.com/w/cpp/language/namespace_alias

		CHECK(fbz::qux == 42);
	}

	SUBCASE("for")
	{
		int sum = 0;
		for (int i = 0; i < 10; i++)
		{
			sum += i;
		}
		//std::cout << "합은: " << sum << std::endl;
		CHECK(sum == 45);
	}

	SUBCASE("while")
	{
		int i = 1;
		int sum = 0;

		while (i <= 10)
		{
			sum += i;
			i++;
		}

		CHECK(i == 11);
		CHECK(sum == 55);
	}

	SUBCASE("if")
	{
		int num = 5;
		bool result = false;

		if (num == 5)
		{
			result = true;
			CHECK(num == 5);
		}
		else
		{
			result = false;
			CHECK(num != 5);
		}

		CHECK(result);
	}

	SUBCASE("switch")
	{
		int age = 1;

		switch (age)
		{
		case 1:
			CHECK(age == 1);
			break;
		case 2:
			CHECK(age == 2);
			break;
		default:
			auto rv = age != 1 && age != 2;
			CHECK(rv);
			break;
		}
	}
}