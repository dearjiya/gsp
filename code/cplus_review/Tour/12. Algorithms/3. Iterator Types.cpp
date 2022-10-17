#include <doctest/doctest.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <vector>

template<typename T>
void print_vec(std::vector<T>& vect)
{
	for (const auto& v : vect)
	{
		std::cout << v << std::endl;
	}
}
TEST_CASE("Algorithms / Iterator Types")
{
	SUBCASE("")
	{
		std::map<int, int> m{ {1, 3} };

		auto iter = m.begin();
		const auto& v = *iter;

		CHECK(v.first == 1);
		CHECK(v.second == 3);
		CHECK(iter->second == 3);
	}

	SUBCASE("iterator �̿��Ͽ� ���� ����ϱ�")
	{
		std::vector<int> vec{ 10,20,5, 30 };
		
	/*	for (auto itr = vec.begin(); itr != vec.end(); ++itr)
		{
			std::cout << *itr << std::endl;
		}*/

		std::vector<int>::iterator itr = vec.begin() + 2;
		CHECK(*itr == 5);
	}

	SUBCASE("iterator erase ����غ���")
	{
		// 20�� ���� �����
		std::vector<int> vec{ 10, 20, 30 };

		for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		{
			if (*itr == 20)
			{
				vec.erase(itr);
				itr = vec.begin();
			}
		}
	}

	SUBCASE("range for")
	{
		std::vector<int> vec{ 1,2,3 };
		std::cout << "vec[i]�� ��Ұ� v�� �����" << std::endl;
		for (int v : vec)
		{
			std::cout << v << std::endl;
		}
		std::cout << "���۷����� ����" << std::endl;
		print_vec(vec);

		auto p = std::make_shared<int>();
	}
}