#include <doctest/doctest.h>
#include <iostream>
#include <vector>

namespace
{
}

TEST_CASE("Basics / Types, Variables and Arithmetic")
{
	/**
	 * Every name and every expression has a type.
	 * type: a set of operations and a set of values
	 * object: a memory which has a value of a specific type
	 * value: a set of bits interpreted according to a type
	 * variable: a named object
	 */
	SUBCASE("type")
	{
		int inch;

		SUBCASE("sizeof")
		{
			CHECK(sizeof(bool) == 1);
			CHECK(sizeof(int) == 4);
		}

	}

	SUBCASE("Arithmetic")
	{
		SUBCASE("How is it done on a computer?")
		{
			// we don't care.
		}

		SUBCASE("bool expressions")
		{
			int a = 1;
			int b = 2;
			bool res = a > b;
			CHECK(res == false);
		}

		SUBCASE("bit expressions")
		{
			auto res1 = 0xFF & 0x00;
			auto res2 = 0xFF | 0x00;
			auto res3 = 0xFF ^ 0x00;
			CHECK(res1 == 0x00);
			CHECK(res2 == 0xFF);
			CHECK(res3 == 0xFF);
			CHECK(~0xFF == -256);
		}
	}

	SUBCASE("Initialization")
	{
		SUBCASE("universal initialization")
		{
			std::vector vs{ 1, 2, 3, 4, 5 };
			CHECK(vs[0] == 1);
		}

		SUBCASE("auto")
		{
			auto d = 0.2;
			auto ch = 'x';
			auto bb{ true };
			auto i{ 1 };
			const char* dd = "double";
			CHECK(strcmp(typeid(d).name(), "double") == 0);
			CHECK(strcmp(typeid(ch).name(), "char") == 0);
			CHECK(strcmp(typeid(bb).name(), "bool") == 0);
			CHECK(strcmp(typeid(i).name(), "int") == 0);
		}
	}

	SUBCASE("Scope and Lifetime")
	{

	}
}