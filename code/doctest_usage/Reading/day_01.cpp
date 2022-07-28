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

	}

	SUBCASE("while")
	{

	}

	SUBCASE("if")
	{

	}

	SUBCASE("switch")
	{

	}
}