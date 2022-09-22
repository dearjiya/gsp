#include<doctest/doctest.h>
#include<iostream>
#include<map>

template <typename K, typename V>
void print_map(std::map<K, V>& m)
{
	// 반복자를 이용한 for문
	//for (auto itr = m.begin(); itr != m.end(); ++itr)
	//{
	//	std::cout << itr->first << " " << itr->second << std::endl;
	//}

	// 범위 기반 for 문
	for (const auto& kv : m) 
	{
		std::cout << kv.first << " " << kv.second << std::endl;
	}
}

template <typename K, typename V>
void search_and_print(std::map<K, V>& m, K key)
{
	auto itr = m.find(key);
	if (itr != m.end())
	{
		std::cout << key << "-->" << itr->second << std::endl;
	}
	else
	{
		std::cout << key << "는 목록에 없습니다" << std::endl;
	}
}

TEST_CASE("player_map")
{
	SUBCASE("map insert")
	{
		std::map<std::string, double> player_list;
		player_list.insert(std::pair<std::string, double>{"순자", 2.23});
		player_list.insert(std::pair<std::string, double>{"영수", 3.31});
		player_list.insert(std::pair<std::string, double>{"영숙", 1.7});

		player_list.insert(std::make_pair("영철", 5.1));
		
		player_list["옥순"] = 4.4;

		print_map(player_list);

		std::cout << "영숙의 방어율은?  " << player_list["영숙"] << std::endl;
	}

	SUBCASE("search and print")
	{
		std::map<std::string, double> p_list;
		p_list.insert(std::make_pair("apple", 2.3));
		
		print_map(p_list);
		std::cout << "-----------------" << std::endl;

		search_and_print(p_list, std::string{ "banana" });
	}

	SUBCASE("duplicated key insert")
	{
		std::map<std::string, double> p_list;
		p_list.insert(std::make_pair("apple", 3.2));
		p_list.insert(std::make_pair("apple", 2.2));
		print_map(p_list);

		std::cout << "-----------------" << std::endl;
		
		p_list["apple"] = 1.1;
		print_map(p_list);
	}
}