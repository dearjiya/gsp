#include <doctest/doctest.h>

TEST_CASE("usage_01")
{
	SUBCASE("sub 01")
	{
		CHECK(1 == 1);
	}

	SUBCASE("sub 02")
	{
		CHECK(true);
	}
}

