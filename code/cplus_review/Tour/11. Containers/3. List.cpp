#include <doctest/doctest.h>

#include <iostream>
#include <vector>
#include <list>

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
}