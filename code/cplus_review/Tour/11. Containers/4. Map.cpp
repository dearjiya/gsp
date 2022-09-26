#include <doctest/doctest.h>

#include <iostream>
#include <vector>
#include <set>
#include <map>

TEST_CASE("Containers / Map")
{
	SUBCASE("std::set 사용하기")
	{
		SUBCASE("vector의 insert와 비교해보기")
		{
			std::vector<int> vec{ 1,2,3 };
			std::vector<int>::iterator vec_itr = vec.begin() + 2;
			vec.insert(vec_itr, 4);

			std::set<int> s{ 10,20,30 };
			s.insert(40);
		}
	}
	SUBCASE("std::map 사용하기")
	{
		std::map<std::string, int> phone_book
		{
			{"David Hume",123456 },
			{ "Karl Popper",234567 },
			{ "Ber trand Ar thur William Russell",345678 }
		};

		std::cout << phone_book["David"] << std::endl;
	}
}