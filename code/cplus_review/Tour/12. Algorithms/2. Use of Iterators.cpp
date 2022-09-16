#include <doctest/doctest.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

TEST_CASE("Algorithms / Use of Iterators")
{
	SUBCASE("algorithm의 사용")
	{
		SUBCASE("vector의 sort")
		{
			std::vector vs{ 3, 2, 5 };

			// Iterator의 종류: sort는 RandomIterator를 받는다.
			// SequentialIterator : list의 경우
			std::sort(vs.begin(), vs.end());

			for (auto& v : vs)
			{
				std::cout << v << std::endl;
			}
		}

		SUBCASE("list의 sort")
		{
			std::list vs{ 3, 2, 5 };
			vs.sort();

			for (auto& v : vs)
			{
				std::cout << v << std::endl;
			}
		}

		SUBCASE("unique_copy")
		{
			// 책의 예시를 실행
			// std::unique_copy();

			std::list<int> lv;
			// 함수인가? 클래스인가? 
			// bi는 back_insert_iterator 클래스 
			// back_insert_iterator는 = 연산자에서 push_back을 lv에 대해 한다.
			auto bi = std::back_inserter(lv);
		}
	}

	SUBCASE("find")
	{
		std::vector<int> s{ 1, 3, 9 };

		auto p = std::find(s.begin(), s.end(), 3); 
		CHECK(*p == 3);
		CHECK(p != s.end());
	}
}