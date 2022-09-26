#include <doctest/doctest.h>

#include <iostream>
#include <vector>
#include <list>

namespace
{
struct Entry
{
	std::string name;
	int number;
};
}

TEST_CASE("Containers / List")
{
	SUBCASE("std::list사용하기")
	{
		std::list<int> li{ 1,3,5 }; 
		std::vector<int> vec{ 1,3,5 };

		auto v_itr = vec.begin();
		auto l_itr = li.begin();
		CHECK(*++v_itr == 3);
		CHECK(*l_itr++ == 3);

		/*for (auto itr = li.begin(); itr != li.end(); ++itr)
		{
			if (*itr == 2)
			{
				li.erase(itr);
				break;
			}
		}*/
	}

	SUBCASE("")
	{
		std::list<Entry> phone_book = {
			{"David",123456},
			{"Karl Popper",234567}, 
			{"Ber trand Ar thur William Russell",345678} 
		};
		for (const auto& x : phone_book)
		{
			if (x.name =="David")
			{
				std::cout << x.number << std::endl;
			}
		}

		for (auto p = phone_book.begin(); p != phone_book.end(); ++p)
		{
			if (p->name == "David")
			{
				std::cout << p->number << std::endl;
			}
		}
	}
}