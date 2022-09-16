#include <doctest/doctest.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

TEST_CASE("Algorithms / Use of Iterators")
{
	SUBCASE("algorithm�� ���")
	{
		SUBCASE("vector�� sort")
		{
			std::vector vs{ 3, 2, 5 };

			// Iterator�� ����: sort�� RandomIterator�� �޴´�.
			// SequentialIterator : list�� ���
			std::sort(vs.begin(), vs.end());

			for (auto& v : vs)
			{
				std::cout << v << std::endl;
			}
		}

		SUBCASE("list�� sort")
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
			// å�� ���ø� ����
			// std::unique_copy();

			std::list<int> lv;
			// �Լ��ΰ�? Ŭ�����ΰ�? 
			// bi�� back_insert_iterator Ŭ���� 
			// back_insert_iterator�� = �����ڿ��� push_back�� lv�� ���� �Ѵ�.
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