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
	SUBCASE("std::multiset 사용하기")
	{
		std::multiset<std::string> s;

		s.insert("a");
		s.insert("b");
		s.insert("a");
		s.insert("c");
		s.insert("d");
		s.insert("c");
	}
	SUBCASE("std::multimap 사용하기")
	{
		std::multimap<int, std::string> m;
		m.insert(std::make_pair(1, "hello"));
		m.insert(std::make_pair(1, "hi"));
		m.insert(std::make_pair(1, "ahihi"));
		m.insert(std::make_pair(2, "bye"));
		m.insert(std::make_pair(2, "baba"));
	}
	SUBCASE("std::unorderedmap 사용하기")
	{
		std::unordered_map<std::string, int> phone_book
		{
			{"David",123456}, 
			{"Karl Popper",234567}, 
			{"Ber trand Ar thur William Russell",345678}
		};
	}
}