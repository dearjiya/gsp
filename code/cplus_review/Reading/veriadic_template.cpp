#include <doctest/doctest.h>

#include<iostream>
#include<string>
#include <vector>

namespace jiya
{
template <typename T>
void print(T arg)
{
	std::cout << arg << std::endl;
}

template<typename T, typename... Types>
void print(T arg, Types... args)
{
	std::cout << arg << ", ";
	print(args...);
}


size_t GetStringSize(const char* s) 
{
	return strlen(s); 
}

size_t GetStringSize(const std::string& s) 
{ 
	return s.size(); 
}

template<typename String, typename... Strings>
size_t GetStringSize(const String& s, Strings... strs)
{
	return GetStringSize(s) + GetStringSize(strs...);
}

void AppendToString(std::string* concat_str)
{
	return;
}
template <typename String, typename... Strings>
void AppendToString(std::string* concat_str, const String& s, Strings... strs)
{
	concat_str->append(s);
	AppendToString(concat_str, strs...);
}


template<typename String>
std::string Strcat(const String& s)
{
	return std::string(s);
}

template<typename String, typename... Strings>
std::string StrCat(const String& s, Strings... strs)
{
	size_t total_size = GetStringSize(s, strs...);
	std::string concat_str;
	concat_str.reserve(total_size);
	concat_str = s;

	AppendToString(&concat_str, strs...);
	return concat_str;
}

int sum_all()
{
	return 0;
}

template <typename... Ints>
int sum_all(int num, Ints... nums)
{
	return num + sum_all(nums...);
}

// sum_all¿ª fold expression¿∏∑Œ
template <typename... Ints>
int fold_sum_all(Ints... nums)
{
	return (... + nums);
}

template <typename... Ints>
double average(Ints... nums)
{
	return static_cast<double>(sum_all(nums...)) / sizeof...(nums);
}
}

TEST_CASE("variadic_tempate")
{
	SUBCASE("print")
	{
		jiya::print(1, 3.1, "abc");
	}

	SUBCASE("concat")
	{
		std::cout << jiya::StrCat(std::string("this"), " ", "is", " ", std::string("a"),
			" ", std::string("sentense"));
	}

	SUBCASE("sizeof...")
	{
		std::cout << jiya::average(1, 4, 2, 3, 19) << std::endl;
	}

	SUBCASE("fold_sum_all")
	{
		std::cout << jiya::fold_sum_all(1, 4, 2, 3, 10) << std::endl;
	}
}
