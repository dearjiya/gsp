#include <doctest/doctest.h>

#include <string>

TEST_CASE("Strings and Regular Expressions / Strings")
{
	SUBCASE("std::string �Ẹ��")
	{
		
	}

	SUBCASE("std::wstring �Ẹ��")
	{
		// UCS16LE encoding
		std::wstring ws{ L"Hello" };
	}
}