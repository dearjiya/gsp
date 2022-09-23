#include <doctest/doctest.h>

#include <iostream>
#include <set>
#include <map>
#include <unordered_map>

template<typename K>
void print_set(const std::multiset<K>& s)
{
	for (const auto& elem : s)
	{
		std::cout << elem << std::endl;
	}
}

TEST_CASE("Containers / Unordered_map")
{
	SUBCASE("std::multiset ����ϱ�")
	{
	}
	SUBCASE("std::multimap ����ϱ�")
	{
	}
	SUBCASE("std::unorderedmap ����ϱ�")
	{
	}
}